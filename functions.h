//
// Created by Marley on 24/04/2023.
//

#ifndef MATRIX_CALCULATOR_FUNCTIONS_H
#define MATRIX_CALCULATOR_FUNCTIONS_H

// Define the maximum size of the matrix
#define MAX 100

void add_matrices(int matrix[MAX][MAX], int m, int c);
void subtract_matrices(int matrix[MAX][MAX], int m, int c);
void multiply_matrices(int matrix[MAX][MAX], int m, int c);
void inverse_matrix(int matrix[MAX][MAX], int m, int c);
void transpose_matrix(int matrix[MAX][MAX], int m, int c);

#endif //MATRIX_CALCULATOR_FUNCTIONS_H
