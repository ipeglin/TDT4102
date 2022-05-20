#include "Game_window.h"
#include "FL/fl_ask.H"
#include "Window.h"

using namespace Graph_lib;

// The game window spawns at the center of the screen
Game_window::Game_window(int board_size,
                         int win_value,
                         int tile_size,
                         const string& title)
	: Window(Point{Fl::w() / 2 - board_size * tile_size / 2,
                   Fl::h() / 2 - board_size * tile_size / 2},
             board_size * tile_size,
             board_size * tile_size,
             title),
	  game{board_size},
	  board_size{board_size}
{
	// Default font for the graphics in this window
	fl_font(cell_font, font_size);

	const Point board_tl{x_max() / 2 - board_size / 2 * tile_size,
	                     y_max() / 2 - board_size / 2 * tile_size};

	// board_sizeXboard_size board
	for (int y = 0; y < board_size; ++y) {
		graphical_tiles.emplace_back();
		for (int x = 0; x < board_size; ++x) {
			Point pos{board_tl.x + x * tile_size, board_tl.y + tile_size * y};
			graphical_tiles.back()
				.emplace_back(std::make_unique<Tile>(pos, tile_size, win_value))
				->attach_to(*this);
		}
	}

	update();
}

void Game_window::reset()
{
	game.new_game();
	update();
}

void Game_window::reset_or_quit(const std::string& q,
                                const std::string& m1,
                                const std::string& m2)
{
	switch (fl_choice("%s", m1.c_str(), m2.c_str(), nullptr, q.c_str())) {
	case 0:
		reset();
		break;
	case 1:
		hide();
		break;
	}
}

void Game_window::update_tiles()
{
	try {
		for (int y = 0; y < board_size; ++y) {
			for (int x = 0; x < board_size; ++x) {
				update_tile(x, y, game.value(x, y));
			}
		}
	} catch (std::out_of_range& e) {
		std::string error =
			"[Debug] We tried to read outside the playing board:\n" +
			std::string{e.what()};
		fl_alert("%s", error.c_str());
	}

	redraw();
}
void Game_window::update()
{
	update_tiles();
	check_status();
}

void Game_window::debug_update() { update_tiles(); }

void Game_window::check_status()
{
	if (game.win()) {
		reset_or_quit(
			"Congratulations, you won the game!", "Play again", "Quit");
	} else if (game.game_over()) {
		reset_or_quit("Game over!", "Play again", "Quit");
	}
}

void Game_window::update_tile(int x, int y, int value)
{
	auto&& rect = graphical_tiles[y][x];
	rect->set_value(value);
}

// Capture key presses and pass to action functions
void Game_window::handle_arrow_key(Arrow_key key)
{
	switch (key) {
	case Arrow_key::up:
		game.move(Direction::up);
		break;
	case Arrow_key::right:
		game.move(Direction::right);
		break;
	case Arrow_key::down:
		game.move(Direction::down);
		break;
	case Arrow_key::left:
		game.move(Direction::left);
		break;
	}

	update();
}

// Capture key presses and pass to action functions
int Game_window::handle(int event)
{
	if (event == FL_KEYDOWN) {
		int key = Fl::event_key();
		switch (key) {
		// Arrow keys
		case FL_Up:
		case FL_Right:
		case FL_Down:
		case FL_Left:
			handle_arrow_key(Arrow_key{key});
			break;

		// For convenience
		// Reset window
		case FL_Key_r:
		case FL_Key_R:
			reset();
			break;

		// All tiles = 2
		case FL_Key_d:
		case FL_Key_D:
			insert_two_tiles();
			break;

		// Tiles in increasing values
		case FL_Key_i:
		case FL_Key_I:
			insert_increasing_tiles();
			break;

		// Tiles for testing push and merge
		case FL_Key_p:
		case FL_Key_P:
			insert_push_merge_tiles();
			break;

		case FL_Key_t:
		case FL_Key_T:
			debug_transpose_tiles();
			break;

		case FL_Key_f:
		case FL_Key_F:
			debug_flip_tiles();
			break;

		// Quit
		case FL_Key_q:
			hide();
			break;

		// Tell FLTK to handle the key event
		default:
			return 0;
		}

		// Tell FLTK that we used and consumed the key
		return 1;
	}
	return 0;
}

void Game_window::insert_two_tiles()
{
	game.debug_all_twos();
	debug_update();
};

void Game_window::insert_increasing_tiles()
{
	game.debug_increasing();
	debug_update();
};

void Game_window::insert_push_merge_tiles()
{
	game.debug_push_merge();
	debug_update();
}

void Game_window::debug_transpose_tiles()
{
	game.debug_transpose();
	debug_update();
};
void Game_window::debug_flip_tiles()
{
	game.debug_flip();
	debug_update();
};