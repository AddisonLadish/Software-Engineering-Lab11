#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

class Matrix {
private:
    int size;
    double** data;

public:
    Matrix();
    Matrix(int n);
    Matrix(const Matrix& other);
    ~Matrix();

    void readFromFile(std::ifstream& file);
    void display() const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    double diagonalSumMain() const;
    double diagonalSumSecondary() const;

    Matrix swapRows(int row1 = 0, int row2 = 1) const;
    Matrix swapCols(int col1 = 0, int col2 = 1) const;
    Matrix updateElement(int row = 0, int col = 0, double value = 100) const;

    int getSize() const { return size; }
};

#endif
