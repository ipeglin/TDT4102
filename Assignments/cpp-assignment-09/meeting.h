#pragma once
#include "utilities.h"
#include "Person.h"

enum class Campus {
    Trondheim = 0,
    Gjøvik,
    Ålesund
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
        std::vector<std::shared_ptr<Person>> participants;

    public:
        int get_day() const;
        int get_start_time() const;
        int get_end_time() const;
        Campus get_location() const;
        std::string get_subject() const;
        std::shared_ptr<Person> get_leader() const;
};