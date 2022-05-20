#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Game.h"
#include "Tile.h"
#include "Window.h"
#include "settings.h"

enum class Arrow_key {
	up = FL_Up,
	right = FL_Right,
	down = FL_Down,
	left = FL_Left
};

class Game_window : public Graph_lib::Window
{
  public:
	Game_window(int board_size,
	            int win_value,
	            int tile_size,
	            const string& title);

  private:
	// Modify the board
	void reset();
	void update();
	void update_tiles();
	void update_tile(int x, int y, int value);

	// Capture key presses and pass to action functions
	int handle(int event) override;
	void handle_arrow_key(Arrow_key key);

	// For debugging under the exam
	void insert_two_tiles();
	void insert_increasing_tiles();
	void insert_push_merge_tiles();
	void debug_transpose_tiles();
	void debug_flip_tiles();
	void debug_update();

	// Misc
	void check_status();
	void reset_or_quit(const std::string& q,
	                   const std::string& m1,
	                   const std::string& m2);

	Game game;
	int board_size;

	std::vector<std::vector<std::unique_ptr<Tile>>> graphical_tiles;
};