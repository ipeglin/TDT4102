#include "MinesweeperWindow.h"
#include "utilities.h"

int main() {
    srand(unsigned(time(nullptr)));
    
	Fl::background(200, 200, 200);
	constexpr int width = 10;
	constexpr int height = 10;
	constexpr int mines = 3;

	Point startPoint{ 200,300 };
	MinesweeperWindow mw{startPoint.x, startPoint.y, width, height, mines, "Minesweeper" };
	return gui_main();
}
