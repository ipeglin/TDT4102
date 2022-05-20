#pragma once
#include <iostream>
#include <vector>

#include "Tile.h"
#include "settings.h"
#include "utilities.h"

enum class Direction { up, right, down, left };

class Game
{
  public:
	Game(int board_size, int win_value = 1024);

	void new_game();

	// The user interface, move up/right/down/left
	void move(Direction direction);
	// We have to provide information of our grid
	// to the outside world
	int value(int x, int y) const;

	// Expose win or game over to class users
	bool win() const;
	bool game_over() const;

	// For debugging
	// You can use these already implemented functions for debugging your game
	friend std::ostream& operator<<(std::ostream& os, const Game& g);
	// The following debug functions should generally not be public for af release
	// build, but we keep them as this to avoid confusion under the exam.
	void debug_all_twos();
	void debug_increasing();
	void debug_push_merge();
	void debug_flip();
	void debug_transpose();

  private:
	enum class Status { playing, win, game_over };
	const int board_size;
	std::vector<int> board;
	int win_value;
	bool moved = false;

	// Calculate 2D index and tile-value access
	int index(int x, int y) const;
	int& at(int x, int y);
	int at(int x, int y) const;

	// Encapsulated logic to perform tile movement
	void move_up();
	void move_right();
	void move_down();
	void move_left();

	// Push and merge
	void push_right();
	void merge_right();

	// Matrix operations
	void transpose();
	void flip();

	// Misc actions
	void place_new_2();
	void tick();

	// Internal status
	bool free_spots() const;
	bool legal_moves() const;
	Status status() const;
};