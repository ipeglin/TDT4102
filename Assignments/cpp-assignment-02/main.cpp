
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

// Oppgave 1
// a
void intput_and_print_int() {
    cout << "Skriv inn et tall: ";
    int input_int;
    cin >> input_int;
    cout << "Du skrev: " << input_int << endl;
}


// b
int input_int() {
    cout << "Skriv inn et tall: ";
    int input_int;
    cin >> input_int;

    return input_int;
}


// c
void input_int_and_print_sum() {
    int num1{input_int()};
    int num2{input_int()};
    cout << "Summen av tallene: " << (num1 + num2);
}


// d
// Fordi kun én av de returnerer en verdi


// e
bool is_odd(int number) {
    return (number % 2 == 1) ? true : false;
}


// f
void print_human_readable_time(int input_seconds) {
    int hour{input_seconds / 3600};
    input_seconds = input_seconds % 3600;
    int min{input_seconds / 60};
    input_seconds = input_seconds % 60;
    int sec{input_seconds};

    cout << hour << " " << (hour == 1 ? "time" : "timer") << " ";
    cout << min << " " << (min == 1 ? "minutt" : "minutter") << " ";
    cout << sec << " " << (sec == 1 ? "sekund" : "sekunder") << endl;
}



// Oppgave 2
// a
void sumarize_given_amount_of_integers() {
    cout << "Hvor mange tall skal adderes: ";
    int amount_of_numbers;
    cin >> amount_of_numbers;

    int sum{0};
    int input{0};
    for (int i = 0; i < amount_of_numbers; i++) {
        cout << "Skriv inn et tall: ";
        cin >> input;
        sum += input;
    }

    cout << "Summen av tallene: " << sum << endl;
}


// b
void sumarize_uknown_amount_of_integers() {
    int sum, input{0};
    do {
        cout << "Skriv inn et tall: ";
        cin >> input;
        sum += input;
    } while (input != 0);

    cout << "Summen av tallene: " << sum << endl;
}


// c
// For løkke for a siden vi vet hvor mange iterasjoner den skal ha
// While løkke for b siden vi ikke vet det


// d
double input_double() {
    cout << "Skriv inn et desimaltall: ";
    double input;
    cin >> input;

    return input;
}


// e
void convert_nok_to_eur() {
    double nok;
    double exchange_rate{9.75};
    do {
        nok = input_double();
    } while (nok >= 0);

    cout << "EUR: " << fixed << setprecision(2) << (nok * exchange_rate) << endl;
}



// Oppgave 3
// b
void create_multiplication_table() {
    cout << "Hvilke dimensjoner skal tabellen ha ({H} {W}): ";
    int height, width;
    cin >> height >> width;

    for (int i = 1; i <= height; i++)
    {
        string row;
        for (int l = 1; l <= width; l++) {
            row += to_string(i *l) + " ";
        }
        cout << row << endl;
    }
}



// Oppgave 4
// a
double discriminant(double a, double b, double c) {
    return (pow(b, 2) - 4 * a * c);
}


// b
void print_real_roots(const double &a, const double &b, const double &c) {
    double disc{discriminant(a, b, c)};
    if (disc < 0) {
        cout << "Ingen reelle løsninger" << endl;
    } else if (disc == 0) {
        cout << "x = " << (-b / (2 * a)) << endl;
    } else {
        cout << "x_1 = " << ((-b + sqrt(disc)) / (2 * a)) << "x_2 = " << ((-b - sqrt(disc)) / (2 * a)) << endl;
    }
}


// c
void solve_quadratic_equation() {
    cout << "Skriv inn tre desimaltall ({a} {b} {c}): ";
    double a, b, c;
    cin >> a >> b >> c;

    print_real_roots(a, b, c);
}



// Oppgave 3a
int main() {
    cout << "Velg funksjon:" << endl
         << "0) Avslutt" << endl
         << "1) Summer to tall" << endl
         << "2) Summer flere tall" << endl
         << "3) Konverter NOK til EUR" << endl 
         << "4) Gangetabell" << endl
         << "5) Løs andregradslikninger" << endl
         << "Angi valg (0-5): ";

    int input;
    cin >> input;

    switch(input) {
        case 0:
            cout << endl << "--------------------------" << endl;
            main();
            break;

        case 1:
            input_int_and_print_sum();
            cout << endl << "--------------------------" << endl;
            main();
            break;

        case 2:
            sumarize_given_amount_of_integers();
            cout << endl << "--------------------------" << endl;
            main();
            break;

        case 3:
            convert_nok_to_eur();
            cout << endl << "--------------------------" << endl;
            main();
            break;

        case 4:
            create_multiplication_table();
            cout << endl << "--------------------------" << endl;
            main();
            break;

        case 5:
            solve_quadratic_equation();
            cout << endl << "--------------------------" << endl;
            main();
            break;

        default:
            cout << endl << "--------------------------" << endl;
            main();
            break;
    }
}