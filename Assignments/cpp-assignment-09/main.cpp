#include "utilities.h"
#include "Person.h"
#include "Car.h"
#include "Meeting.h"

int main() {
    // Oppgave 2
    std::shared_ptr<Person> person_1(new Person("Kari Nordmann", "kari.nordmann@stereotype.com"));
    std::shared_ptr<Person> person_2(new Person("Ola Nordmann", "ola.nordmann@norsk.com", std::make_unique<Car>(5)));

    std::cout << *person_1 << std::endl;
    std::cout << *person_2 << std::endl;


    // Oppgave 3
    Meeting meeting_1(2, 1300, 1400, Campus::Trondheim, "How to pass TDT4102 without the use of cookbooks 101", person_1);
    meeting_1.get_participant_list();
}