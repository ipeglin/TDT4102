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



Meeting::Meeting(int day, int start_time, int end_time, Campus location, std::string subject, std::shared_ptr<Person> &leader) 
    : day{day},
    start_time{start_time},
    end_time{end_time},
    location{location},
    subject{subject},
    leader{leader} {
        add_participant(leader);
    }

Meeting::~Meeting() {
    std::cout << "Instance deleted (Meeting): Subject -> " << subject << std::endl;
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

std::vector<std::string> Meeting::get_participant_list() const {
    std::vector<std::string> name_vector{};

    for (std::shared_ptr<Person> person_ptr : participants) {
        name_vector.push_back(person_ptr.get()->get_name());
    }

    return name_vector;
}



void Meeting::add_participant(std::shared_ptr<Person> const person) {
    participants.push_back(person);
}



std::vector<std::shared_ptr<Person>> Meeting::find_potenional_co_driving(const Meeting &other_meeting) const {
    std::vector<std::shared_ptr<Person>> potential_co_drivers{};

    if (location == other_meeting.get_location() && day == other_meeting.get_day() && (std::abs(start_time - other_meeting.get_start_time()) <= 100) && (std::abs(end_time - other_meeting.get_end_time()) <= 100)) {
        for (std::shared_ptr<Person> person_ptr : other_meeting.participants) {
            if (person_ptr.get()->has_available_seats()) {
                potential_co_drivers.push_back(person_ptr);
            }
        }
    }

    return potential_co_drivers;
}



std::ostream &operator<<(std::ostream &os, const Meeting &meeting) {
    os << "Day: " << meeting.get_day() << std::endl
       << "Starting: " << meeting.get_start_time() << std::endl
       << "Ending: " << meeting.get_end_time() << std::endl
       << "Location: " << meeting.get_location() << std::endl
       << "Subject: " << meeting.get_subject() << std::endl
       << "Meeting leader: " << meeting.get_leader().get()->get_name() << std::endl;

    return os;
}