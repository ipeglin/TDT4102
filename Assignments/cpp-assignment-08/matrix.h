#pragma once
#include "utilities.h"

class Matrix {
    private:
        int matrix_rows;
        int matrix_columns;
        double **matrix;
    public:
        Matrix(int height, int width);
        explicit Matrix(int height);
        ~Matrix();

        double *operator[](int index);
        friend std::ostream& operator<<(std::ostream& os, Matrix& matrix);

        double get(int row, int column) const;
        void set(int row, int column, double value);

        int get_rows();
        int get_columns();
};