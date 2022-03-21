#include "utilities.h"
#include "person.h"
#include "car.h"
#include "meeting.h"

int main() {
    // Oppgave 1
    Person person_1("Ola Normann", "ola@normann.no");
    
    Car car_1(4);
    Person person_2("Kari Normann", "kari@normann.no", &car_1);

    std::cout << person_1 << std::endl;
    std::cout << person_2 << std::endl;


    // Oppgave 2
    Campus campus{Campus::Trondheim};
    std::cout << campus << std::endl;


    // Oppgave 3
    std::shared_ptr<Person> meeting_leader = std::make_shared<Person>("Ian Philip Eglin", "philip@eglin.no");

    Meeting meeting(1, 12, 14, Campus::Trondheim, "How to pass TDT4102 without a cookbook 101", meeting_leader);
    std::cout << meeting << std::endl;
}