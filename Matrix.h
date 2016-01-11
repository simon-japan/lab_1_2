//
// Created by SJ Holland on 1/11/16.
//

#ifndef LAB_1_2_MATRIX_H
#define LAB_1_2_MATRIX_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

namespace Simon {

    class Matrix {

    public:
        Matrix();

        ~Matrix();

        Matrix(const Matrix & m); // Copy constructor
        Matrix operator=(const Matrix & m); // Assignment operator

        void load(std::vector<std::string> lines);

        friend std::ostream & operator << (std::ostream & os, Matrix & m);

        Matrix operator+(const Matrix & m);

        Matrix operator-(const Matrix & m);

        const double get(const int row, const int column) const;

        static const int ROWS = 3;
        static const int COLUMNS = 3;
        typedef double MATRIX_VALUES[ROWS][COLUMNS];
        MATRIX_VALUES values;

    };

}

#endif //LAB_1_2_MATRIX_H
