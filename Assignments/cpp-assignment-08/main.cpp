#include "utilities.h"
#include "fibonacci.h"
#include "matrix.h"
#include "intermezzo.h"

int main() {
    // 1)
    // create_fibonacci();

    // 2)
    Matrix matrix_1(3,2);
	std::cout << matrix_1;
	std::cout << std::endl;

    Matrix matrix_2{matrix_1};
    std::cout << matrix_2 << std::endl;

    Matrix identity_matrix(4);
	std::cout << identity_matrix << std::endl;

    Matrix matrix_3(identity_matrix);
    std::cout << matrix_3 << std::endl;

    // 3)
    // dummy_test();
}