#include "course_catalog.h"

void Course_catalog::add_course(std::string course_code, std::string course_name) {
    if (course_code != "" && course_name != "") {
        catalog.insert(std::pair<std::string, std::string>(course_code, course_name));
    }
}

void Course_catalog::remove_course(std::string course_code) {
    if (catalog.find(course_code) != catalog.end()) {
        catalog.erase(course_code);
    }
}

std::string Course_catalog::get_course(std::string course_code) {
    return catalog.at(course_code);
}

void Course_catalog::save_catalog() {
    std::ofstream target_stream;
    target_stream.open(storage_location);

    for (std::pair<std::string, std::string> item : catalog) {
        target_stream << item.first << "," << item.second << std::endl;
    }

    target_stream.close();
}

void Course_catalog::load_catalog() {
    std::ifstream source_stream;
    source_stream.open(storage_location);

    std::string line;
    std::string temp_string;

    catalog.clear();

    while (getline(source_stream, line)) {
        catalog.insert(std::pair<std::string, std::string>(line.substr(0, line.find(",")), line.substr(line.find(",") + 1)));
    }
}

std::ostream& operator<<(std::ostream& os, const Course_catalog& course_catalog) {
    for (std::pair<std::string, std::string> item : course_catalog.catalog) {
        os << item.first << ": " << item.second << std::endl;
    }
    return os;
}