// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void transposeMatrix() {
    int rows, columns;
    int original[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    readMatrix(original, rows, columns);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transposed[j][i] = original[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    printMatrix(original, rows, columns);

    cout << "\nTransposed Matrix:\n";
    printMatrix(transposed, columns, rows);
}

void addMatrices() {
    int rows, columns;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int sumMatrix[MAX_SIZE][MAX_SIZE];

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    cout << "\nEnter elements for Matrix A:\n";
    readMatrix(matrixA, rows, columns);

    cout << "\nEnter elements for Matrix B:\n";
    readMatrix(matrixB, rows, columns);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "\nMatrix A + Matrix B Result:\n";
    printMatrix(sumMatrix, rows, columns);
}

void multiplyMatrices() {
    int rowsA, columnsA, rowsB, columnsB;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int productMatrix[MAX_SIZE][MAX_SIZE];

    cout << "Enter rows for Matrix A: ";
    cin >> rowsA;
    cout << "Enter columns for Matrix A: ";
    cin >> columnsA;

    cout << "Enter rows for Matrix B: ";
    cin >> rowsB;
    cout << "Enter columns for Matrix B: ";
    cin >> columnsB;

    if (columnsA != rowsB) {
        cout << "Error: Columns of Matrix A must match Rows of Matrix B!\n";
        return;
    }

    cout << "\nEnter elements for Matrix A:\n";
    readMatrix(matrixA, rowsA, columnsA);

    cout << "\nEnter elements for Matrix B:\n";
    readMatrix(matrixB, rowsB, columnsB);

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            productMatrix[i][j] = 0;
            for (int k = 0; k < columnsA; k++) {
                productMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "\nMatrix A * Matrix B Result:\n";
    printMatrix(productMatrix, rowsA, columnsB);
}

int main() {
    cout << "--- PART A: TRANSPOSE MATRIX ---\n";
    transposeMatrix();

    cout << "\n--- PART B: ADD MATRICES ---\n";
    addMatrices();

    cout << "\n--- PART C: MULTIPLY MATRICES ---\n";
    multiplyMatrices();

    return 0;
}
