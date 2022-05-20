#pragma once
#include "FL/Enumerations.H"
#include <cmath>
#include <cstdlib>

// The following code is provided as part of the exam in TDT4102
// You are not required to read or understand it.

union RGBA {
	// Be aware of endianness
	// This is OK for tdt4102 2021 and the assumptions we make
	uint32_t rgba = 0;
	struct {
		uint8_t a;
		uint8_t b;
		uint8_t g;
		uint8_t r;
	} c;
};

uint8_t lerp(uint8_t begin, uint8_t end, uint8_t n, uint8_t N);

Fl_Color lerp_rgb(Fl_Color begin, Fl_Color end, uint8_t n, uint8_t N);
