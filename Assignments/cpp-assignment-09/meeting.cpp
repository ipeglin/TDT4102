#include "meeting.h"

std::ostream& operator<<(std::ostream &os, const Campus &campus) {
    switch(campus) {
        case Campus::Trondheim:
            os << "Trondheim";
            break;
        case Campus::Ålesund:
            os << "Ålesund";
            break;
        case Campus::Gjøvik:
            os << "Gjøvik";
            break;
        default:
            os << "";
            break;
    }

    return os;
}

Meeting::Meeting(int day, int start, int end, Campus meeting_location, std::string meeting_subject, std::shared_ptr<Person> meeting_leader) :
    day{day}, 
    start_time{start}, 
    end_time{end}, 
    location{meeting_location}, 
    subject{meeting_subject}, 
    leader{meeting_leader} {
        this->add_participant(meeting_leader);
        meetings.insert(this);
    }


Meeting::~Meeting() {
    std::cout << "The folling meeting was deleted from heap" << std::endl
              << *this << std::endl;
    meetings.erase(this);
}

std::ostream& operator<<(std::ostream& os, const Meeting& meeting) {
    os << "Starting: " << meeting.get_start_time() << std::endl
       << "Ending: " << meeting.get_end_time() << std::endl
       << "Location: " << meeting.get_location() << std::endl
       << "Subject: " << meeting.get_subject() << std::endl
       << "Meeting leader: " << meeting.get_leader().get()->get_name() << std::endl;

    return os;
}

int Meeting::get_day() const {
    return this->day;
}

int Meeting::get_start_time() const {
    return this->start_time;
}

int Meeting::get_end_time() const {
    return this->end_time;
}

Campus Meeting::get_location() const {
    return this->location;
}

std::string Meeting::get_subject() const{ 
    return this->subject;
}

std::shared_ptr<Person> Meeting::get_leader() const {
    return this->leader;
}

std::vector<std::string> Meeting::get_participant_list() const {
    std::vector<std::string> meeting_participants;

    for (std::shared_ptr<Person> person : this->participants) {
        meeting_participants.push_back(person.get()->get_name());
    }

    return meeting_participants;
}

void Meeting::add_participant(std::shared_ptr<Person> const new_participant) {
    this->participants.emplace_back(new_participant.get());
}

std::vector<std::shared_ptr<Person>>Meeting::find_potential_co_driving(Meeting other_meeting) const {
    std::vector<std::shared_ptr<Person>> temp_vector{};

    if (this->location == other_meeting.get_location() && this->day == other_meeting.get_day() && std::abs(this->start_time - other_meeting.get_start_time()) < 1 && std::abs(this->end_time - other_meeting.get_end_time()) < 1) {
        for (std::shared_ptr<Person> const &person : other_meeting.participants) {
            if (person->has_available_seats()) {
                temp_vector.push_back(person);
            }
        }
    }

    return temp_vector;
}