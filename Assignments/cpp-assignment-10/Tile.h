#pragma once
#include "GUI.h"


// De forskjellige tilstandene en Tile kan vaere i
enum class Cell { closed, open, flagged }; 

class Tile : public Fl_Button {
	private:
		Cell state = Cell::closed;
		bool is_mine = false;

		void set_label(string s) { this->copy_label(s.c_str());}
		void set_label_color(Color c) {this->labelcolor(c.as_int());}
	public:
		Tile(Point pos, int size) 
			:Fl_Button(pos.x, pos.y, size, size, "") {};

		bool get_mine_state() const { return is_mine; };
		void set_mine_state(bool new_state) { is_mine = new_state; };

		void open();
		void flag();

		Cell get_state() const { return state; };
		void set_state(Cell new_state) { state = new_state; };

		void set_adj_mines(int n);
};
