#include "utilities.h"
#include "Person.h"
#include "Car.h"
#include "Meeting.h"

int main() {
    // Oppgave 1
    std::shared_ptr<Person> person_1(new Person("Kari Nordmann", "kari.nordmann@stereotype.com"));
    std::shared_ptr<Person> person_2(new Person("Ola Nordmann", "ola.nordmann@norsk.com", std::make_unique<Car>(5)));

    std::cout << *person_1 << std::endl;
    std::cout << *person_2 << std::endl;
}