#pragma once
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji {
    protected:
        Point centre;
        int radius;

    public:
        Face(Point centre, int radius) : centre{centre}, radius{radius} {};
        virtual ~Face(){};
        virtual void draw(AnimationWindow &win) override = 0;
};

class Empty_face : public Face {
    protected:
        vector<Point> eye_position{Point{centre.x + static_cast<int>(radius * 0.3), centre.y - static_cast<int>(radius * 0.25)}, Point{centre.x - static_cast<int>(radius * 0.3), centre.y - static_cast<int>(radius * 0.25)}};
        int eye_radius{static_cast<int>(radius * 0.2)};

    public:
        Empty_face(Point centre, int radius) : Face{centre, radius} {};
        virtual void draw(AnimationWindow &win);
};

class Smiley_face : public Empty_face {
    protected:
        Point mouth_position{centre.x, static_cast<int>(centre.y * 1.1)};

    public:
        Smiley_face(Point centre, int radius) : Empty_face{centre, radius} {};
        virtual void draw(AnimationWindow &win);
};

class Sad_face : public Empty_face {
    protected:
        Point mouth_position{centre.x, static_cast<int>(centre.y * 1.25)};

    public:
        Sad_face(Point centre, int radius) : Empty_face{centre, radius} {};
        virtual void draw(AnimationWindow &win);
};

class Angry_face : public Sad_face {
    protected:
        vector<vector<Point>> brow_positions{{Point{static_cast<int>(eye_position.at(0).x - 0.5 * eye_radius), static_cast<int>(eye_position.at(0).y - eye_radius)}, Point{static_cast<int>(eye_position.at(0).x + 0.5 * eye_radius), static_cast<int>(eye_position.at(0).y - 2 * eye_radius)}}, {{Point{static_cast<int>(eye_position.at(1).x + 0.5 * eye_radius), static_cast<int>(eye_position.at(1).y - eye_radius)}, Point{static_cast<int>(eye_position.at(1).x - 0.5 * eye_radius), static_cast<int>(eye_position.at(1).y - 2 * eye_radius)}}}};

    public:
        Angry_face(Point centre, int radius) : Sad_face{centre, radius} {};
        virtual void draw(AnimationWindow &win);
};

class Winkey_face : public Empty_face {
    protected:
        Point mouth_position{centre.x, static_cast<int>(centre.y * 1.1)};

    public:
        Winkey_face(Point centre, int radius) : Empty_face{centre, radius} {};
        virtual void draw(AnimationWindow &win);
};

class Surprised_face : public Empty_face {
    protected:
        Point mouth_position{centre.x, static_cast<int>(centre.y * 1.2)};
    
    public:
        Surprised_face(Point centre, int radius) : Empty_face{centre, radius} {};
        virtual void draw(AnimationWindow &win);
};