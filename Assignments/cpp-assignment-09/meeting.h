#pragma once
#include "utilities.h"
#include "person.h"
#include "car.h"

enum class Campus {
    Trondheim,
    Ålesund,
    Gjøvik
};

std::ostream &operator<<(std::ostream &os, const Campus &campus);

class Meeting {
    private:
        int day;
        int start_time;
        int end_time;
        Campus location;
        std::string subject;
        const std::shared_ptr<Person> leader;
        std::vector<std::shared_ptr<Person> const> participants{};

        static inline std::set<const Meeting *> meetings{};

    public:
        Meeting(int day, int start, int end, Campus meeting_location, std::string meeting_subject, std::shared_ptr<Person> const meeting_leader);
        ~Meeting();

        int get_day() const;
        int get_start_time() const;
        int get_end_time() const;
        Campus get_location() const;
        std::string get_subject() const;
        std::shared_ptr<Person> get_leader() const;
        std::vector<std::string> get_participant_list() const;

        void add_participant(std::shared_ptr<Person> const new_participant);

        std::vector<std::shared_ptr<Person>> find_potential_co_driving(Meeting other_meeting) const;
};

std::ostream& operator<<(std::ostream& os, const Meeting& meeting);