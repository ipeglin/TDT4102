#include "MinesweeperWindow.h"

template <typename T>
void remove_at(std::vector<T> &vector, typename std::vector<T>::size_type index) {
	std::swap(vector.at(index), vector.back());
	vector.pop_back();
}

template <typename T>
int get_random_vector_index(std::vector<T> const &vector) {
	return rand() % (vector.size() - 1);
}

template <typename T, typename Q>
int get_random_map_key(std::map<T, Q> const &map) {
	auto itr = map.begin();

	std::advance(itr, rand() % map.size());
	T random_key {itr->first};

	return random_key;
}

template <typename T>
T get_random_element_and_remove(std::vector<T> &vector) {
	int index {get_random_vector_index(vector)};
	T randomly_chosen_element {vector.at(index)};
	remove_at(vector, index);

	return randomly_chosen_element;
}


MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines}, 
	end_screen{0, 0, width * cellSize, height * cellSize} {
		std::map<int, vector<int>> mine_position_map{};

		// Legg til alle tiles i vinduet
		for (int i = 0; i < height; ++i) {
			// std::vector<int> temp_vec{};
			mine_position_map.insert(std::pair<int, std::vector<int>>(i, {}));

			for (int j = 0; j < width; ++j) {
				mine_position_map.at(i).push_back(j);

				tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
				tiles.back()->callback(cb_click, this);
				add(tiles.back().get());
			}
		}

		for (int y_coor = 0; y_coor < mines; y_coor++) {
			int x_pos {get_random_map_key(mine_position_map)};
			int y_pos {get_random_element_and_remove(mine_position_map.at(x_pos))};
			tiles.at(y_pos * width + x_pos)->set_mine_state(true);
			std::cout << "Placing mine at (" << x_pos << ", " << y_pos << ")" << std::endl;
		}

		// Legger til miner paa tilfeldige posisjoner
		

		// Fjern window reskalering
		resizable(nullptr);
		size_range(x_max(), y_max(), x_max(), y_max());
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	std::shared_ptr<Tile> &tile_ptr {this->at(xy)};

	if (tile_ptr.get()->get_state() != Cell::closed) {
		return;
	}
	
	tile_ptr.get()->open();

	if (tile_ptr.get()->get_mine_state()) {
		add(end_screen);
		end_screen.value("You won!");

		return;
	} else {
		int number_adjacent_mines{count_mines(adjacentPoints(xy))};
		number_opened_mines++;

		if (number_adjacent_mines > 0) {
			tile_ptr.get()->set_adj_mines(number_adjacent_mines);
		}

		if (number_adjacent_mines == 0) {
			for (Point pnt : adjacentPoints(xy)) {
				openTile(pnt);
			}
		}
	}

	if (number_opened_mines == (height * width - mines)) {
		add(end_screen);
		end_screen.value("Game over! You hit a mine");

		return;
	}
}



void MinesweeperWindow::flagTile(Point xy) {
	Cell tile_state {this->at(xy).get()->get_state()};
	if (tile_state == Cell::closed || tile_state == Cell::flagged) {
		this->at(xy).get()->flag();
	}
}

int MinesweeperWindow::count_mines(std::vector<Point> point_vector) {
	int mine_count {0};

	for (Point &pnt : point_vector) {
		if (this->at(pnt).get()->get_mine_state()) {
			mine_count++;
		}
	}

	return mine_count;
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::click()
{
	Point xy{Fl::event_x(), Fl::event_y()};

	MouseButton mb = static_cast<MouseButton>(Fl::event_button());

	if (!inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		openTile(xy);
		break;
	case MouseButton::right:
		flagTile(xy);
		break;
	}
}
