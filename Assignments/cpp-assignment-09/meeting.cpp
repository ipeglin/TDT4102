#include "Meeting.h"

std::ostream& operator<<(std::ostream &os, const Campus &campus) {
    switch(campus) {
        case Campus::Trondheim:
            os << "Trondheim";
            break;
        case  Campus::Gjøvik:
            os << "Gjøvik";
            break;
        case Campus::Ålesund:
            os << "Ålesund";
            break;
        default:
            os << "Invalid campus";
            break;
    }

    return os;
}



int Meeting::get_day() const {
    return day;
}

int Meeting::get_start_time() const {
    return start_time;
}

int Meeting::get_end_time() const {
    return end_time;
}

Campus Meeting::get_location() const {
    return location;
}

std::string Meeting::get_subject() const {
    return subject;
}

std::shared_ptr<Person> Meeting::get_leader() const {
    return leader;
}