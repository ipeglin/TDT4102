#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "Emoji.h"
#include "emoji_main.h"

constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emoji_radius = 50;

void print_emojis() {
	Point face_centre{100, 100};

	std::vector<std::unique_ptr<Emoji>> emojis;
	
	emojis.emplace_back(new Smiley_face(face_centre, emoji_radius));
	emojis.emplace_back(new Sad_face(face_centre, emoji_radius));
	emojis.emplace_back(new Angry_face(face_centre, emoji_radius));
	emojis.emplace_back(new Winkey_face(face_centre, emoji_radius));
	emojis.emplace_back(new Surprised_face(face_centre, emoji_radius));

	for (auto &emoji : emojis) {
		const Point tl{100, 100};
		const string win_label{"Emoji factory"};
		AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};
		emoji->draw(win);
		win.wait_for_close();
	}

}