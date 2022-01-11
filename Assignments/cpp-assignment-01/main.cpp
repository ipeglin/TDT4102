
#include<iostream>

using namespace std; // To eliminate the need for writing std::cout


// Oppgave 1
/*
# Function checking is a number in the fibonacci sequence
def is_fibonacci_number(n):
    a = 0
    b = 1
    while (b < n):
        temp = b;
        b += a
        a = temp

    return b == n
*/



// Oppgave 2

// a
// Determining which of two integers are the largest
int max_of_two(int a, int b) {
    if (a > b) {
        cout << "A is greater than B" << endl;
        return a;
    } else {
        cout << "B is greater than A" << endl;
        return b;
    }
}


// c 
// Returns the (n+1)th fib number. Prints n numbers of the fibonacci sequence
int fibonacci(int n) {
    int a{0};
    int b{1};

    cout << "Fibonacci numbers:" << endl;
    for (int x = 0; x < n; x++) {
        cout << x << " " << b << endl;
        int temp{b};
        b += a;
        a = temp;
    }
    cout << "----" << endl;
    return b;
}


// d
// Returns the sum of the n first square numbers
int square_number_sum(int n) {
    int total_sum{0};
    for (int i = 0; i < n; i++) {
        total_sum += i * i;
        cout << (i * i) << endl;
    }
    cout << total_sum << endl;
    return total_sum;
}


// e
// Prints all triangle numbers under n
void triangle_numbers_below(int n) {
    int acc{1};
    int num{2};
    cout << "Triangle numbers below " << n << ":" << endl;
    while (acc < n) {
        cout << acc << endl;
        acc += num;
        num += 1;
    }
    cout << endl;
}


// f
bool is_prime(int n) {
    for (int j = 2; j < n; j++) {
        if (n % j == 0) {
            return false;
        }
    }

    return true;
}


// g
// Checking for prime numbers between 2 and n
void naive_prime_number_search(int n) {
    for (int number = 2; number < n; number++) {
        if (is_prime(number)) {
            cout << number << " is a prime" << endl;
        }
    }
}


// h
int find_greatest_divisor(int n) {
    for (int divisor = (n - 1); divisor > 0; divisor--) {
        if (n % divisor == 0) {
            return divisor;
        }
    }
}

//  Oppgave 2B!!
// Main function calling once on all functions
int main() {
    cout << "Oppgave a)" << endl;
    cout << max_of_two(5, 6) << endl;

    cout << "Oppgave c)" << endl;
    cout << fibonacci(7) << endl;

    cout << "Oppgave d)" << endl;
    cout << square_number_sum(9) << endl;

    cout << "Oppgave e)" << endl;
    triangle_numbers_below(14);

    cout << "Oppgave f)" << endl;
    cout << is_prime(13) << endl;

    cout << "Oppgave g)" << endl;
    naive_prime_number_search(19);

    cout << "Oppgave h)" << endl;
    cout << find_greatest_divisor(91) << endl;

    return 0;
}