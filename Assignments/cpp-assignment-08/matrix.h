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
        int get_rows();

        /**
         * @brief Get number of columns in matrix
         * 
         * @return int 
         */
        int get_columns();
};