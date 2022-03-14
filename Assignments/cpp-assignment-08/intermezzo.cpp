#include "intermezzo.h"

/* 3a)
 * Først vil alle dummiene skrive ut tallet 4 siden alle refererer til den samme minneaddressen.
 * Siden alle endrer verdi ved samme minneaddresse vil alle sammen bli endret til 5 når *c.num = 5 utføres.
 */

Dummy::Dummy() {
    num = new int{0};
}

Dummy::Dummy(const Dummy& dummy) {
    num = new int{*dummy.num};
}

Dummy::~Dummy() {
    delete num;
}

Dummy Dummy::operator=(Dummy& dummy) {
    num = new int{*dummy.num};
    return *this;
}

void dummy_test() {
    Dummy a;

    *a.num = 4;

    Dummy b{a};
    Dummy c;

    c = a;

    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n';
    std::cout << "c: " << *c.num << '\n';

    *b.num = 3;
    *c.num = 5;

    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n';
    std::cout << "c: " << *c.num << '\n';
}
