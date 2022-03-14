#include "matrix.h"

Matrix::Matrix(int height, int width) : matrix_rows{height}, matrix_columns{width} {
    assert(height > 0 && width > 0);
    matrix = new double *[height];

    for (int row_number = 0; row_number < height; row_number++) {
        matrix[row_number] = new double[width];

        for (int col_number = 0; col_number < width; col_number++) {
            matrix[row_number][col_number] = 0;
        }
    }
}

Matrix::Matrix(int width) : Matrix(width, width) {
    for (int index = 0; index < width; index++) {
        matrix[index][index] = 1;
    }
}

Matrix::~Matrix() {
    for (int row_number = 0; row_number < matrix_rows; row_number++) {
        delete[] matrix[row_number];
        matrix[row_number] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
}

double Matrix::get(int row, int column) const {
    assert(row < matrix_rows && row >= 0 && column < matrix_columns && column >= 0);
    return matrix[row][column];
}

void Matrix::set(int row, int column, double value) {
    assert(row < matrix_rows && row >= 0 && column < matrix_columns && column >= 0);
    matrix[row][column] = value;
}

double *Matrix::operator[](int index) {
    return matrix[index];
}

std::ostream& operator<<(std::ostream& os, Matrix& matrix) {
    for (int row_number = 0; row_number < matrix.matrix_rows; row_number++) {
        for (int col_number = 0; col_number < matrix.matrix_columns; col_number++) {
            os << std::setw(3) << matrix[row_number][col_number] << " ";
        }
        os << std::endl;
    }
    return os;
}

int Matrix::get_rows() {
    return matrix_rows;
}

int Matrix::get_columns() {
    return matrix_columns;
}