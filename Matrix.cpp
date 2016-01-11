//
// Created by SJ Holland on 1/11/16.
//

#include "Matrix.h"

namespace Simon {

    Matrix::Matrix() {
        for (int i = 0; i < ROWS; i ++) {
            for (int j = 0; j < COLUMNS; j++) {
                values[i][j] = 0;
            }
        }
    }

    Matrix::~Matrix() {

    }

    Matrix::Matrix(const Matrix & m) {
        for (int i = 0; i < ROWS; i ++) {
            for (int j = 0; j < COLUMNS; j++) {
                values[i][j] = m.get(i, j);
            }
        }
    }

    Matrix Matrix::operator = (const Matrix &m) {
        Matrix tmp(m);
        std::swap(values, tmp.values);
        return * this;
    }

    Matrix Matrix::operator + (const Matrix & m) {
        Matrix result;
        for (int i = 0; i < ROWS; i ++) {
            for (int j = 0; j < COLUMNS; j++) {
                result.values[i][j] = values[i][j] + m.get(i,j);
            }
        }
        return result;
    }

    Matrix Matrix::operator - (const Matrix & m) {
        Matrix result;
        for (int i = 0; i < ROWS; i ++) {
            for (int j = 0; j < COLUMNS; j++) {
                result.values[i][j] = values[i][j] - m.get(i,j);
            }
        }
        return result;
    }

    const double Matrix::get(const int row, const int column) const {
        return values[row][column];
    }

    void Matrix::load(std::vector<std::string> lines) {
        for (int i=0; i<ROWS; i++)
        {
            std::string line(lines[i]);
            std::istringstream iss(line);
            double word;
            for (int j=0; j < COLUMNS; j++)
            {
                iss >> word;
                values[i][j] = word;
            }
        }
    }

    std::ostream & operator << (std::ostream & os, Matrix & m) {
        for (int i = 0; i < Matrix::ROWS; i ++) {
            for (int j = 0; j < Matrix::COLUMNS; j++) {
                os << m.values[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
}