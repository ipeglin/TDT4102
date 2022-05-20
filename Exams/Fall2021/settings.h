#pragma once

#include "Graph.h"
#include "FL/Enumerations.H"

// Global constants for the 1024 game

// Constants for handling FLTK
// alpha key presses (ASCII codes)
constexpr int FL_Key_D = 'D';
constexpr int FL_Key_d = 'd';
constexpr int FL_Key_F = 'F';
constexpr int FL_Key_f = 'f';
constexpr int FL_Key_I = 'I';
constexpr int FL_Key_i = 'i';
constexpr int FL_Key_P = 'P';
constexpr int FL_Key_p = 'p';
constexpr int FL_Key_q = 'q';
constexpr int FL_Key_R = 'R';
constexpr int FL_Key_r = 'r';
constexpr int FL_Key_T = 'T';
constexpr int FL_Key_t = 't';

// We have some default values for the fonts
// we use in the graphical representation
constexpr Fl_Font cell_font = Graph_lib::Font::helvetica;
constexpr int font_size = 16;