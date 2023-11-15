
#include "Matrix.h"
#include <iostream>
#include <math.h>
#include <time.h>
#include <utility>
#include <iomanip>

using namespace std;



int main()
{
    Matrix<int> matrix1(3, 3), matrix2(3, 3);
    
    cout << "Column: " << matrix1.getColumn() << endl;
    cout << " Row:   " << matrix1.getRow() << endl;
    cout << endl << endl;
    cout << "Matrix 1" << endl;
    matrix1.print();
    cout << endl << endl;

    Matrix<int> matrix3(matrix1);

    cout << "Matrix 3" << endl;
    matrix3.print();
    cout << endl << endl;
    cout << "Matrix 2" << endl;
    matrix2.fillMatrixRand(3, 3);
    matrix2.print();
    cout << endl << endl;
    cout << matrix2.getMatrixIJ(2, 1) << endl;
    cout << endl << endl;

    //Matrix<int> matrix4(3, 3);
    //matrix4.fillMatrixHand(3, 3);
    //matrix4.print();
    //cout << endl << endl;

    cout << "Sum matrix1 and matrix2:" << endl;
    matrix1 + matrix2;
    matrix1.print();
    cout << endl << endl;
    cout << "Subtraction matrix1 and matrix2:" << endl;
    matrix1 - matrix2;
    matrix1.print();
    
    Matrix<int> matrix4(3, 3);
    matrix4 = matrix1 * matrix2;
    matrix1.print();


}


