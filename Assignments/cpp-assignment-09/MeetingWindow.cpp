#include "MeetingWindow.h"

void MeetingWindow::cb_quit(Fl_Widget*, void* pw) {
    static_cast<MeetingWindow *>(pw)->hide();
}