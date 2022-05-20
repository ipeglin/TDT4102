#include "utilities.h"

// The following code is provided as part of the exam in TDT4102
// You are not required to read or understand it.

// We use the following code to perform linear interpolation on
// FLTK RGB Colors.

uint8_t lerp(uint8_t begin, uint8_t end, uint8_t n, uint8_t N)
{
	// Linear interpolation
	// Returns a number in the interval [begin, end]
	// with N total steps ([0, N-1])
	// n = 0 => begin
	// n = N => end
	return (end - begin) * n / N + begin;
}

Fl_Color lerp_rgb(Fl_Color begin, Fl_Color end, uint8_t n, uint8_t N)
{
	// Component-wise lerp of RGB
	RGBA b{begin};
	RGBA e{end};
	RGBA lerped;

	lerped.c.r = lerp(b.c.r, e.c.r, n, N);
	lerped.c.g = lerp(b.c.g, e.c.g, n, N);
	lerped.c.b = lerp(b.c.b, e.c.b, n, N);

	return lerped.rgba;
}