#include "Game.h"

Game::Game(int board_size, int win_value)
	: board_size(board_size),
	  board(board_size * board_size),
	  win_value{win_value}
{
	new_game();
}

// TASK
int Game::index(int x, int y) const
{
	// BEGIN: G1
	return board_size * y + x;
	// END: G1
}

// TASK
int Game::at(int x, int y) const
{
	// BEGIN: G2
	if ((x >= board_size || x < 0) || (y >= board_size || y < 0))
		throw std::out_of_range("Index out of range, (x, y) = (" + to_string(x) + ", " + to_string(y) + ").");

	return board.at(index(x, y));
	// END: G2
};

// TASK
int &Game::at(int x, int y)
{
	// BEGIN: G3
	if ((x >= board_size || x < 0) || (y >= board_size || y < 0))
		throw std::out_of_range("Index out of range, (x, y) = (" + to_string(x) + ", " + to_string(y) + ").");

	return board.at(index(x, y));
	// END: G3
}

// TASK
void Game::new_game()
{
	// BEGIN: G4
	for (int &cell : board)
	{
		cell = 0;
	}

	place_new_2();
	place_new_2();
	// END: G4
}

// TASK
// Prerequisites: board does have a free 0-spot
void Game::place_new_2()
{
	// BEGIN: G5
	std::vector<int> zero_indexes;
	for (int index = 0; index < board.size(); index++)
	{
		if (index != 0)
			continue;

		zero_indexes.push_back(index);
	}

	board.at(rand() % board_size - 1) = 2;
	// END: G5
}

// TASK
void Game::flip()
{
	// BEGIN: G6
	std::cout << "Flipping" << std::endl;
	for (int row = 0; row < board_size; ++row)
	{
		for (int col = 0; col < board_size / 2; ++col)
		{
			std::swap(at(col, row), at(board_size - col - 1, row));
		}
	}

	// for (int row = 0; row < board_size; ++row)
	// {
	// 	for (int col = 0; col < (board_size / 2); ++col)
	// 	{
	// 		int current_index{index(col, row)};
	// 		int current_number{board.at(current_index)};

	// 		int target_index{index((col % board_size), row)};
	// 		int target_number{board.at(target_index)};

	// 		board.at(target_index) = current_number;
	// 		board.at(current_index) = target_number;
	// 	}
	// 	}
	// END: G6
}

// TASK
void Game::transpose()
{
	// BEGIN: G7
	std::cout << "Transposing" << std::endl;
	for (int row = 0; row < board_size; ++row)
	{
		for (int col = 0; col < board_size; ++col)
		{
			std::swap(at(col, row), at(row, col));
		}
	}

	// END: G7
}

// TASK
void Game::push_right()
{
	// BEGIN: G8
	for (int row = 0; row < board_size; ++row)
	{
		std::list<int> new_row;

		for (int col = 0; col < board_size; ++col)
		{
			int value = at(col, row);

			if (value != 0)
			{
				new_row.push_back(value);
			}
			else
			{
				new_row.push_front(0);
			}
		}

		for (int col = 0; col < board_size; ++col)
		{
			at(col, row) = new_row.front();
			new_row.pop_front();
		}
	}
	// END: G8
}

// TASK
void Game::merge_right()
{
	// BEGIN: G9
	for (int row = 0; row < board_size; ++row)
	{
		for (int col = board_size - 1; 0 < col; --col)
		{
			int &current_value = at(col, row);
			int &prev_value = at(col - 1, row);

			if (current_value != prev_value)
				continue;

			current_value = 2 * prev_value;
			prev_value = 0;
		}
	}
	// END: G9
}

// TASK
void Game::move_right()
{
	// BEGIN: G10
	push_right();
	merge_right();
	push_right();
	// END: G10
}

// TASK
void Game::move_down()
{
	// BEGIN: G11
	transpose();
	move_right();
	transpose();
	// END: G11
}

// TASK
void Game::move_left()
{
	// BEGIN: G12
	flip();
	move_right();
	flip();
	// END: G12
}

// TASK
void Game::move_up()
{
	// BEGIN: G13
	transpose();
	move_left();
	transpose();
	// END: G13
}

// TASK
bool Game::free_spots() const
{
	// BEGIN: G14
	for (const int &cell : board)
	{
		if (cell == 0)
			return true;
	}

	return false;
	// END: G14
}

// TASK
void Game::tick()
{
	// BEGIN: G15
	if (moved && free_spots())
	{
		place_new_2();
	}
	// END: G15
}

// TASK
bool Game::win() const
{
	// BEGIN: G16
	for (const int &cell : board)
	{
		if (cell == win_value)
		{
			return true;
		}
	}

	return false;
	// END: G16
}

// TASK
// Prerequisites: all tiles are non-zero
bool Game::legal_moves() const
{
	// BEGIN: G17
	for (int row = 0; row < board_size; ++row)
	{
		for (int col = 0; col < board_size - 1; ++col)
		{
			if (at(col, row) == at(col + 1, row))
				return true;
		}
	}

	for (int row = 0; row < board_size; ++row)
	{
		for (int col = 0; col < board_size; ++col)
		{
			if (at(col, row) == at(col, row + 1))
				return true;
		}
	}

	return false;
	// END: G17
}

/**** Provided code ****/

// API version of tile value - const external interface
int Game::value(int x, int y) const { return at(x, y); }

// This function keeps track of changes to the board
// and calls the move function requested by the player
void Game::move(Direction direction)
{
	// We have not moved any tiles yet
	moved = false;

	// Keep the old board matrix for comparison
	std::vector<int> old_board{board};

	if (status() == Status::playing)
	{
		switch (direction)
		{
		case Direction::up:
			move_up();
			break;
		case Direction::right:
			move_right();
			break;
		case Direction::down:
			move_down();
			break;
		case Direction::left:
			move_left();
			break;
		}
	}

	// Did we move anything?
	if (board != old_board)
	{
		moved = true;
	}

	tick();
}

// We use this to figure out if a game
// is won, game over or if the player still
// can play legal moves
Game::Status Game::status() const
{
	if (win())
	{
		return Status::win;
	}

	if (free_spots() || legal_moves())
	{
		return Status::playing;
	}

	return Status::game_over;
}

bool Game::game_over() const { return status() == Status::game_over; }

std::ostream &operator<<(std::ostream &os, const Game &g)
{
	for (int i = 0; i < g.board_size; ++i)
	{
		for (int j = 0; j < g.board_size; ++j)
		{
			std::cout << g.at(j, i) << " ";
		}
		std::cout << '\n';
	}

	return os;
}

// Debug methods - debug API
void Game::debug_all_twos()
{
	static const std::array<int, 16> debug_board_all_twos{
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

	std::copy(debug_board_all_twos.begin(),
			  debug_board_all_twos.end(),
			  board.begin());
	tick();
}

void Game::debug_increasing()
{
	static const std::array<int, 16> debug_board_increasing{
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

	std::copy(debug_board_increasing.begin(),
			  debug_board_increasing.end(),
			  board.begin());
	tick();
}

void Game::debug_push_merge()
{
	// clang-format off
	static const std::array<int, 16> debug_board_push_merge{
		2,0,2,0,
		0,2,2,4,
		0,2,2,2,
		8,8,8,8
	};
	// clang-format on

	std::copy(debug_board_push_merge.begin(),
			  debug_board_push_merge.end(),
			  board.begin());
	tick();
}

void Game::debug_flip() { flip(); }
void Game::debug_transpose() { transpose(); }
