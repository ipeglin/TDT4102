#include "utilities.h"
#include "fibonacci.h"
#include "matrix.h"
#include "intermezzo.h"

int main() {
    
    // 1)
    create_fibonacci();

    // 2)
    Matrix matrix_1(2, 3);
    std::cout << "Matrix 1:" << std::endl
              << matrix_1 << std::endl;

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

    Matrix D{B * A_2};

    std::cout << "Matrix B:" << std::endl
              << B << std::endl;

    std::cout << "Matrix A_2:" << std::endl
              << A_2 << std::endl;

    std::cout << "Matrix D (B * A_2):" << std::endl
              << D << std::endl;

    B *= C;    
    std::cout << "NEW Matrix B (B *= C):" << std::endl
              << B << std::endl;

    Matrix matrix_2{matrix_1}; // Test the overloaded = operator
    std::cout << "Matrix 2:" << std::endl<< matrix_2 << std::endl;

    Matrix identity_matrix(4); // Testing the explicit constructor
	std::cout << "Indentity Matrix:" << std::endl<< identity_matrix << std::endl;

    Matrix matrix_3(identity_matrix); // Testing deep copy constructor
    std::cout << "Matrix 3:" << std::endl<< matrix_3 << std::endl;

    // 3)
    dummy_test();
}