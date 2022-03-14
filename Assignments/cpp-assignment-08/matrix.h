#pragma once
#include "utilities.h"

/**
 * @brief Matrix class
 * 
 */
class Matrix {
    private:
        int matrix_rows;
        int matrix_columns;

        double **matrix;
        
    public:
        /**
         * @brief Construct a new M x N Matrix
         * 
         * @param height Number of rows
         * @param width Number of columns
         */
        Matrix(int height, int width);

        /**
         * @brief Construct a new M x M identity matrix
         * 
         * @param height Number of rows and columns
         */
        explicit Matrix(int height);

        /**
         * @brief Construct a deep copy of another Matrix
         * 
         * @param ref_matrix Instance of Matrix class
         */
        Matrix(const Matrix &ref_matrix);

        /**
         * @brief Destroy the Matrix object
         * 
         */
        ~Matrix();


        /**
         * @brief Get double pointer at matrix position
         * 
         * @param index Row index
         * @return double* 
         */
        double *operator[](int index);

        /**
         * @brief Create a copy of another Matrix by reference
         * 
         * @param ref_matrix Instance of matrix class
         * @return Matrix 
         */
        Matrix operator=(Matrix ref_matrix);

        /**
         * @brief Add another matrix to the current instance
         * 
         * @param other_matrix Instance of Matrix class
         * @return Matrix 
         */
        Matrix operator+=(Matrix other_matrix);

        /**
         * @brief Create new Matrix instance of the sum of two matrices.
         * 
         * @param other_matrix Instance of Matrix class
         * @return Matrix 
         */
        Matrix operator+(Matrix other_matrix);
        
        /**
         * @brief Subtract another matrix from the current instance
         * 
         * @param other_matrix Insatnce of Matrix class
         * @return Matrix 
         */
        Matrix operator-=(Matrix other_matrix);

        /**
         * @brief Create new Matrix instance of the difference of two matrices.
         * 
         * @param other_matrix Instance of Matrix class
         * @return Matrix 
         */
        Matrix operator-(Matrix other_matrix);

        /**
         * @brief Print matrix to console
         * 
         * @param os Output stream
         * @param matrix Matrix instance
         * @return std::ostream& 
         */
        friend std::ostream& operator<<(std::ostream& os, Matrix& matrix);


        /**
         * @brief Get value at matrix position
         * 
         * @param row Row number
         * @param column Column number
         * @return double 
         */
        double get(int row, int column) const;

        /**
         * @brief Set value at matrix position
         * 
         * @param row Row number
         * @param column Column number
         * @param value New value to be stored
         */
        void set(int row, int column, double value);

        /**
         * @brief Get number of rows in matrix
         * 
         * @return int 
         */
        int get_rows() const;

        /**
         * @brief Get number of columns in matrix
         * 
         * @return int 
         */
        int get_columns() const;
};