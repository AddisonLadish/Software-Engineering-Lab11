#include "Matrix.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filename;
    cout << "Enter input filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file.\n";
        return 1;
    }

    Matrix A, B;
    A.readFromFile(file);
    B.readFromFile(file);
    file.close();

    cout << "\nMatrix A:\n";
    A.display();

    cout << "\nMatrix B:\n";
    B.display();

    cout << "\nA + B:\n";
    (A + B).display();

    cout << "\nA * B:\n";
    (A * B).display();

    cout << "\nMain diagonal sum of A: " << A.diagonalSumMain() << endl;
    cout << "Secondary diagonal sum of A: " << A.diagonalSumSecondary() << endl;

    cout << "\nSwapping rows 0 and 1 in A:\n";
    A.swapRows().display();

    cout << "\nSwapping columns 0 and 1 in A:\n";
    A.swapCols().display();

    cout << "\nUpdating element (2,2) in A to 99:\n";
    A.updateElement(2, 2, 99).display();

    return 0;
}
