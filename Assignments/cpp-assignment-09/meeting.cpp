#include "Meeting.h"
#include "utilities.h"

std::ostream& operator<<(std::ostream &os, const Campus &campus) {
    switch(campus) {
        case Campus::Trondheim:
            os << "Trondheim";
            break;
        case  Campus::Gjøvik:
            os << "Gjøvik";
            break;
        case Campus::Ålesund:
            os << "Ålesund";
            break;
        default:
            os << "Invalid campus";
            break;
    }

    return os;
}