#include "utilities.h"
#include "fibonacci.h"
#include "matrix.h"

int main() {
    // 1)
    create_fibonacci();

    // 2)
    Matrix m(5,3);
	std::cout << m;
	std::cout << std::endl;
	Matrix n(5);
	std::cout << n;
}