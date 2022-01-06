#include "AnimationWindow.h"
#include "std_lib_facilities.h"

int main() {
	// Open a window
    AnimationWindow window;

    // Draw a circle at the point (100, 100), with a radius of 50
    window.draw_circle({100, 100}, 50);
    
    // Ensure the window remains open until closed. 
    // Otherwise the program exits, and you don't get to see the fruits of your labour
    window.wait_for_close();
}