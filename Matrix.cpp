#include "Matrix.h"
using namespace std;

// Default constructor
Matrix::Matrix() {
    size = 0;
    data = nullptr;
}

// Parameterized constructor
Matrix::Matrix(int n) {
    size = n;
    data = new double*[size];
    for (int i = 0; i < size; ++i)
        data[i] = new double[size];
}

// Copy constructor
Matrix::Matrix(const Matrix& other) {
    size = other.size;
    data = new double*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];
        for (int j = 0; j < size; ++j)
            data[i][j] = other.data[i][j];
    }
}

// Destructor
Matrix::~Matrix() {
    if (data) {
        for (int i = 0; i < size; ++i)
            delete[] data[i];
        delete[] data;
    }
}

// Read matrix from file stream
void Matrix::readFromFile(ifstream& file) {
    file >> size;
    data = new double*[size];
    for (int i = 0; i < size; ++i)
        data[i] = new double[size];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            file >> data[i][j];
}

// Display matrix neatly
void Matrix::display() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cout << setw(6) << data[i][j];
        cout << endl;
    }
}

// Operator overloading for addition
Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

// Operator overloading for multiplication
Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < size; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
        }
    return result;
}

// Main diagonal sum
double Matrix::diagonalSumMain() const {
    double sum = 0;
    for (int i = 0; i < size; ++i)
        sum += data[i][i];
    return sum;
}

// Secondary diagonal sum
double Matrix::diagonalSumSecondary() const {
    double sum = 0;
    for (int i = 0; i < size; ++i)
        sum += data[i][size - i - 1];
    return sum;
}

// Swap two rows (by value)
Matrix Matrix::swapRows(int row1, int row2) const {
    Matrix result(*this);
    if (row1 >= 0 && row2 >= 0 && row1 < size && row2 < size) {
        for (int j = 0; j < size; ++j) {
            double temp = result.data[row1][j];
            result.data[row1][j] = result.data[row2][j];
            result.data[row2][j] = temp;
        }
    }
    return result;
}

// Swap two columns (by value)
Matrix Matrix::swapCols(int col1, int col2) const {
    Matrix result(*this);
    if (col1 >= 0 && col2 >= 0 && col1 < size && col2 < size) {
        for (int i = 0; i < size; ++i) {
            double temp = result.data[i][col1];
            result.data[i][col1] = result.data[i][col2];
            result.data[i][col2] = temp;
        }
    }
    return result;
}

// Update an element (by value)
Matrix Matrix::updateElement(int row, int col, double value) const {
    Matrix result(*this);
    if (row >= 0 && col >= 0 && row < size && col < size)
        result.data[row][col] = value;
    return result;
}
