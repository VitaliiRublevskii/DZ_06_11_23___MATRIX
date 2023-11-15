#pragma once
#include <iostream>
#include <math.h>
#include <time.h>
#include <utility>
#include <iomanip>
using namespace std;

template<typename T> class Matrix
{
	T rows = 0;  
	T columns = 0;  
	T** matrix = nullptr;

public:
    Matrix() {}

    Matrix( T _rows, T _columns) : rows(_rows), columns(_columns) {
        matrix = (T**) new T*[rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = (T*)new T[columns];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                matrix[i][j] = 8;
       
    };

    Matrix(const Matrix& _matrix) {
        rows = _matrix.rows;
        columns = _matrix.columns;
        matrix = (T**) new T * [rows]; 

        for (int i = 0; i < rows; i++)
            matrix[i] = (T*) new T[columns];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                matrix[i][j] = _matrix.matrix[i][j];
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];

        delete[] matrix;
    }
    
    void fillMatrixRand(int rows, int columns)
    {
        srand(time(0));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                matrix[i][j] = rand() % 20 + 1;
    }

    void fillMatrixHand(int rows, int columns)
    {
        
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++) {
                T x = NULL;
                cout << "Enter  x ";
                cin >> x;
                matrix[i][j] = x;
            }
                
    }

    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << matrix[i][j] << " ";
            }

            cout << endl;
        }
    }

    int getRow()
    {
        return rows;
    };
    int getColumn()
    {
        return columns;
    };
    T getMatrixIJ(int i, int j) {
        if ((rows > 0) && (columns > 0))
            return matrix[i][j];
        else
            return 0;
    }
    void SetMatrixIJ(int i, int j, T value)
    {
        if ((i < 0) || (i >= rows))
            return;
        if ((j < 0) || (j >= columns))
            return;
        matrix[i][j] = value;
    }
    

    //Перегрузка оператора умножения +:
    Matrix& operator+(Matrix& _matrix) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                matrix[i][j] += _matrix.matrix[i][j];
        return  *this;
    }
    //Перегрузка оператора умножения -:
    Matrix& operator-(Matrix& _matrix) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                matrix[i][j] -= _matrix.matrix[i][j];
        return  *this;
    }
     
    
    //Перегрузка оператора умножения *:
    Matrix& operator*(Matrix& _matrix) {
        Matrix new_matrix(3, 3);

        for (int i = 0; i < columns; i++)
            for (int j = 0; j < columns; j++)
                for (int k = 0; k < columns; k++)
                    new_matrix[i][j] += matrix[i][k] * _matrix[k][j];
        return new_matrix;
    }

};

