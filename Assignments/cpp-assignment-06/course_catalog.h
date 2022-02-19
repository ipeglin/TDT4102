#pragma once
#include "utilities.h"


class Course_catalog {
    private:
        std::map<std::string, std::string> catalog;
        const std::string storage_location{"Course Catalog Content.txt"};

    public:
        void add_course(std::string course_code, std::string course_name);
        void remove_course(std::string course_code);
        std::string get_course(std::string course_code);
        void save_catalog();
        void load_catalog();
        friend std::ostream& operator<<(std::ostream&, const Course_catalog&);
};