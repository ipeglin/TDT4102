#include "Tile.h"

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const map<int, Color> mines_to_color {
	{1, Color::blue},
	{2, Color::red},
	{3, Color::dark_green},
	{4, Color::dark_magenta},
	{5, Color::dark_blue},
	{6, Color::dark_cyan},
	{7, Color::dark_red},
	{8, Color::dark_yellow}
};

// For aa sette Tilelabel i henhold til state
const map<Cell, string> cell_to_symbol {
	{Cell::closed, ""},
	{Cell::open, ""},
	{Cell::flagged, "@<"}
};

void Tile::open() {
	if (get_state() == Cell::closed) {
		this->set(); // Setter en button som trykket paa, tilsvarer aapnet rute
		this->set_state(Cell::open);
		if (this->get_mine_state()) {
			this->set_label("X");
			this->set_label_color(mines_to_color.at(2));
		}
	}
}

void Tile::flag() {
	if (get_state() == Cell::flagged) {
		this->set_state(Cell::closed);
		this->set_label(cell_to_symbol.at(Cell::closed));
	} else {
		this->set_state(Cell::flagged);
		this->set_label(cell_to_symbol.at(Cell::flagged));
		this->set_label_color(mines_to_color.at(1));
	}
}

void Tile::set_adj_mines(int n) {
	assert(n > 0 && n <= 8);

	this->set_label(std::to_string(n));
	this->set_label_color(mines_to_color.at(n));
}