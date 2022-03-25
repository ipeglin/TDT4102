#include "MeetingWindow.h"

void MeetingWindow::cb_quit(Fl_Widget*, void* pw) {
    static_cast<MeetingWindow *>(pw)->hide();
}

void MeetingWindow::cb_new_person(Fl_Widget*, void* pw) {
    static_cast<MeetingWindow *>(pw)->new_person();
}

void MeetingWindow::new_person() {
    if (static_cast<std::string>(person_name.value()) != "" && static_cast<std::string>(person_email.value()) != "") {
        people.emplace_back(new Person{person_name.value(), person_email.value()});
    }
    person_name.value("");
    person_email.value("");
}

void MeetingWindow::show_people() {
    for (std::shared_ptr<Person> person_ptr : people) {
        std::cout << *person_ptr << std::endl;
    }
}