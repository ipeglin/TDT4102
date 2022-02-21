#include "Emoji.h"
#include "std_lib_facilities.h"

void Face::draw(AnimationWindow &win) {
    win.draw_circle(centre, radius, Color::yellow); 
}

void Empty_face::draw(AnimationWindow &win) {
    Face::draw(win);
    
    for (Point &position : eye_position) {
        win.draw_circle(position, eye_radius, Color::black);
    }   
}

void Smiley_face::draw(AnimationWindow &win) {
    Empty_face::draw(win);

    win.draw_arc(mouth_position, radius , radius * 0.8, 180, 360);
}

void Sad_face::draw(AnimationWindow &win) {
    Empty_face::draw(win);

    win.draw_arc(mouth_position, radius, radius * 0.8, 0, 180);
}

void Angry_face::draw(AnimationWindow &win) {
    Sad_face::draw(win);

    for (auto &brow : brow_positions) {
        win.draw_line(brow.at(0), brow.at(1));
    }
}

void Winkey_face::draw(AnimationWindow &win) {
    Face::draw(win);

    win.draw_circle(eye_position.at(1), eye_radius, Color::black);
    win.draw_arc(eye_position.at(0), 2 * eye_radius, 2 * eye_radius, 0, 180);
    win.draw_arc(mouth_position, radius, radius * 0.8, 180, 360);
}

void Surprised_face::draw(AnimationWindow &win) {
    Empty_face::draw(win);

    win.draw_arc(mouth_position, radius * 0.5, radius * 0.5, 0, 360);
}