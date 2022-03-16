#include "utilities.h"
#include "fibonacci.h"
#include "matrix.h"
#include "intermezzo.h"

int main() {
    // 1)
    create_fibonacci();

    // 2)
    Matrix matrix_1(2, 3);
    std::cout << matrix_1;
	std::cout << std::endl;

    Matrix A(2, 3);
    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4);

    Matrix A_2(3, 2);
    A_2.set(0, 0, 1);
    A_2.set(0, 1, 2);
    A_2.set(1, 0, 3);
    A_2.set(1, 1, 4);
    A_2.set(2, 0, 0);
    A_2.set(2, 1, 0);

    Matrix B(2, 2);
    B.set(0, 0, 4);
    B.set(0, 1, 3);
    B.set(1, 0, 2);
    B.set(1, 1, 1);

    Matrix C(2, 2);
    C.set(0, 0, 1);
    C.set(0, 1, 3);
    C.set(1, 0, 1.5);
    C.set(1, 1, 2.0);

    // B *= A;
    Matrix D{B * A};
    Matrix E{B * A_2};
    std::cout << D << std::endl;
    std::cout << E << std::endl;

    Matrix matrix_4{matrix_1}; // Test the overloaded = operator
    std::cout << matrix_4 << std::endl;

    Matrix identity_matrix(4); // Testing the explicit constructor
	std::cout << identity_matrix << std::endl;

    Matrix matrix_5(identity_matrix); // Testing deep copy constructor
    std::cout << matrix_5 << std::endl;

    // 3)
    dummy_test();
}