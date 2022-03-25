#include "utilities.h"
#include "AnimationWindow.h"
#include "GUI.h"
#include "Graph.h"
#include "Person.h"

class MeetingWindow : public AnimationWindow {
    private:
        static constexpr int padding_top{30};
        static constexpr int field_width{300};
        static constexpr int field_height{40};
        static constexpr int field_padding_left{50};

        Fl_Button quit_button;
        Fl_Button new_person_button;
        Fl_Input person_name;
        Fl_Input person_email;

        std::vector<std::shared_ptr<Person>> people{};

    public:
        MeetingWindow(int x, int y, int w, int h, const std::string &title)
            : AnimationWindow(x, y, w, h, title), 
            quit_button{static_cast<int>(w * 0.3), static_cast<int>((h * 0.8)), static_cast<int>(w * 0.4), static_cast<int>(h * 0.1), "Quit"},
            new_person_button{static_cast<int>(w * 0.3), static_cast<int>((h * 0.7)), static_cast<int>(w * 0.4), static_cast<int>(h * 0.1), "Add new person"},
            person_name{field_padding_left, padding_top, field_width, field_height, "Name"},
            person_email{field_padding_left, padding_top * 4, field_width, field_height, "Email"} {
                add(quit_button);
                add(new_person_button);
                add(person_name);
                add(person_email);
                quit_button.callback(cb_quit, this);
                new_person_button.callback(cb_new_person, this);
            }

        static void cb_quit(Fl_Widget*, void* pw);
        static void cb_new_person(Fl_Widget*, void* pw);

        void new_person();
        void show_people();
};