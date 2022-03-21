#include "utilities.h"
#include "person.h"
#include "car.h"
#include "meeting.h"

int main() {
    Person person_1("Ola Normann", "ola@normann.no");
    
    Car car_1(4);
    Person person_2("Kari Normann", "kari@normann.no", &car_1);

    std::cout << person_1 << std::endl;
    std::cout << person_2 << std::endl;

    Campus campus{Campus::Trondheim};
    std::cout << campus << std::endl;
}