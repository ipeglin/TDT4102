#include "utilities.h"
#include "person.h"
#include "car.h"
#include "meeting.h"

int main() {
    // Oppgave 1
    std::unique_ptr<Car> car_1 = std::make_unique<Car>(5);
    std::unique_ptr<Car> car_2 = std::make_unique<Car>(0);
    std::unique_ptr<Car> car_3 = std::make_unique<Car>(4);

    std::shared_ptr<Person> person_1 = std::make_shared<Person>("Ola Normann", "ola@normann.no");
    std::shared_ptr<Person> person_2 = std::make_shared<Person>("Kari Normann", "kari@normann.no", car_1);
    std::shared_ptr<Person> person_3 = std::make_shared<Person>("Leif Eriksson", "leif.eriksson@viking.no", car_3);
    std::shared_ptr<Person> person_4 = std::make_shared<Person>("Olav Haraldsson", "olavtheholy@viking.no", car_2);
    

    std::cout << person_1 << std::endl;
    std::cout << person_2 << std::endl;
    std::cout << person_3 << std::endl;
    std::cout << person_4 << std::endl;

    // Oppgave 2
    Campus campus{Campus::Trondheim};
    std::cout << campus << std::endl;


    // Oppgave 3
    Meeting meeting_1(11, 1200, 1400, Campus::Trondheim, "How to pass TDT4102 without a cookbook 101", person_1);
    Meeting meeting_2(11, 1300, 1500, Campus::Trondheim, "How to fail statistics TMA4245", person_4);

    std::cout << meeting_1 << std::endl;
    std::cout << meeting_2 << std::endl;

    meeting_1.add_participant(person_3);
    meeting_2.add_participant(person_4);


    std::vector<std::shared_ptr<Person>> co_drivers{meeting_1.find_potential_co_driving(meeting_2)};
    // for (std::shared_ptr<Person> &person : co_drivers) {
    //     std::cout << "Potential co-driver: " << person.get()->get_name() << std::endl;
    // }
}