#pragma once
#include "Graph.h"
#include "Point.h"
#include "Window.h"

struct Tile {
	static inline constexpr Fl_Color YELLOW = 0xFEF00100;
	static inline constexpr Fl_Color DARK_ORANGE = 0xF0050500;

	Tile(Graph_lib::Point pos, int size, int max_value);
	void init();
	void set_value(int value);
	void center_label();
	void attach_to(Graph_lib::Window& win);

  private:
	Graph_lib::Rectangle rect;
	Graph_lib::Text label;
	int size;
	int max_value;
};