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

Matrix::Matrix(const Matrix &ref_matrix) {
    this->matrix_rows = ref_matrix.get_rows();
    this->matrix_columns = ref_matrix.get_columns();
    this->matrix = new double *[this->matrix_rows];

    for (int row_number = 0; row_number < this->matrix_rows; row_number++) {
        matrix[row_number] = new double[this->matrix_columns];

        for (int col_number = 0; col_number < this->matrix_columns; col_number++) {
            this->matrix[row_number][col_number] = ref_matrix.matrix[row_number][col_number];
        }
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

Matrix Matrix::operator=(Matrix ref_matrix) {
    std::swap(matrix_rows, ref_matrix.matrix_rows);
    std::swap(matrix_columns, ref_matrix.matrix_columns);
    std::swap(matrix, ref_matrix.matrix);

    return *this;
}

Matrix Matrix::operator+=(Matrix other_matrix) {
    for (int row_number = 0; row_number < matrix_rows; row_number++) {
        for (int col_number = 0; col_number < matrix_columns; col_number++) {
            matrix[row_number][col_number] += other_matrix.matrix[row_number][col_number];
        }
    }

    return *this;
}

Matrix Matrix::operator+(Matrix other_matrix) {
    Matrix sum{other_matrix};
    sum += *this;

    return sum;
}

Matrix Matrix::operator-=(Matrix other_matrix) {
    for (int row_number = 0; row_number < matrix_rows; row_number++) {
        for (int col_number = 0; col_number < matrix_columns; col_number++) {
            matrix[row_number][col_number] -= other_matrix.matrix[row_number][col_number];
        }
    }

    return *this;
}

Matrix Matrix::operator-(Matrix other_matrix) {
    Matrix difference{*this};
    difference -= other_matrix;

    return difference;
}

std::ostream& operator<<(std::ostream& os, Matrix& matrix) {
    for (int row_number = 0; row_number < matrix.matrix_rows; row_number++) {
        for (int col_number = 0; col_number < matrix.matrix_columns; col_number++) {
            os << std::setw(4) << matrix[row_number][col_number] << " ";
        }
        os << std::endl;
    }

    return os;
}

int Matrix::get_rows() const {
    return matrix_rows;
}

int Matrix::get_columns() const {
    return matrix_columns;
}