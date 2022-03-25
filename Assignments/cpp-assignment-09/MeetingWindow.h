#include "utilities.h"
#include "AnimationWindow.h"
#include "GUI.h"
#include "Graph.h"

class MeetingWindow : public AnimationWindow {
    private:
        static constexpr int padding_top{1};
        static constexpr int button_width{1};
        static constexpr int button_height{1};
        static constexpr int field_width{1};
        static constexpr int field_height{1};
        static constexpr int field_padding_left{1};

        Fl_Button quit_button;

    public:
        MeetingWindow(int x, int y, int w, int h, const std::string &title) : AnimationWindow(x, y, w, h, title), quit_button{static_cast<int>(w * 0.3), static_cast<int>((h * 0.8)), static_cast<int>(w * 0.4), static_cast<int>(h * 0.1), "Quit"} {
            add(quit_button);
            quit_button.callback(cb_quit, this);
        }

        static void cb_quit(Fl_Widget*, void* pw);
};