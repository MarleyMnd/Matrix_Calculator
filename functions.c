//
// Created by Marley on 24/04/2023.
//

#include <stdio.h>
#define MAX 100

// Addition of 2 matrices
void add_matrices(int matrix[MAX][MAX], int r, int c) {
    int matrix2[MAX][MAX];

    printf("Please enter the values of the second matrix.\n");
    printf("Note: The number of rows and columns must be the same as the first matrix \033[0;32m(%d x %d)\033[0;0m.\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("\tValue at \033[0;32m(%d;%d)\033[0;0m: ", i + 1, j + 1);
            scanf_s(" %d", &matrix2[i][j]);
        }
    }

    int sum[MAX][MAX];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }

    for (int i = 0; i < 20; i++) {
        printf("\n");
    }

    printf("The sum of the two matrices is the following matrix:\n\n");
    printf("\t ");
    for (int k = 0; k < c; k++) {
        printf("\033[0;35m--------");
    }
    printf("\n");
    for (int i = 0; i < r; i++) {
        printf("\t|  ");
        for (int j = 0; j < c; j++) {
            printf("\033[0;0m%3d    \033[0;35m", sum[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("\t ");
    for (int k = 0; k < c; k++) {
        printf("--------");
    }
    printf("\033[0;0m");
    printf("\n");
}


// Subtraction of 2 matrices
void subtract_matrices(int matrix[MAX][MAX], int r, int c) {
    int matrix2[MAX][MAX];

    printf("Please enter the values of the second matrix.\n");
    printf("Note: The number of rows and columns must be the same as the first matrix \033[0;32m(%d x %d)\033[0;0m.\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("\tValue at \033[0;32m(%d;%d)\033[0;0m: ", i + 1, j + 1);
            scanf_s(" %d", &matrix2[i][j]);
        }
    }

    int sum[MAX][MAX];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = matrix[i][j] - matrix2[i][j];
        }
    }

    printf("The sum of the two matrices is the following matrix:\n");
    printf("\t ");
    for (int k = 0; k < c; k++) {
        printf("\033[0;35m------");
    }
    printf("\n");
    for (int i = 0; i < r; i++) {
        printf("\t|  ");
        for (int j = 0; j < c; j++) {
            printf("\033[0;0m%d    \033[0;35m", sum[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("\t ");
    for (int k = 0; k < c; k++) {
        printf("------");
    }
    printf("\033[0;0m");
    printf("\n");
}

// Multiplication of 2 matrices
void multiply_matrices(int matrix[MAX][MAX], int r1, int c1) {
    int matrix2[MAX][MAX];

    printf("Please enter the values of the second matrix.\n");
    printf("\nNote: The number of rows and columns must be the same as the first matrix \033[0;32m(%d x %d)\033[0;0m.\n", c1, r1);
    for (int i = 0; i < c1; i++) {
        for (int j = 0; j < r1; j++) {
            printf("\tValue at \033[0;32m(%d;%d)\033[0;0m: ", i + 1, j + 1);
            scanf_s(" %d", &matrix2[i][j]);
        }
    }

    int r2 = c1;
    int c2 = r1;

    int product[MAX][MAX];

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++){
            product[i][j] = 0;
            for (int k = 0; k < r2; k++) {
                product[i][j] += matrix[i][k] * matrix2[k][j];
            }
        }
    }

    printf("\nThe product of the two matrices is the following matrix:\n\n");
    printf("\t ");
    for (int k = 0; k < c2; k++) {
        printf("\033[0;35m--------");
    }
    printf("\n");
    for (int i = 0; i < r1; i++) {
        printf("\t|  ");
        for (int j = 0; j < c2; j++) {
            printf("\033[0;0m%3d    \033[0;35m", product[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("\t ");
    for (int k = 0; k < c2; k++) {
        printf("--------");
    }
    printf("\033[0;0m");
    printf("\n");
}


// Function to find the inverse of a 2x2 matrix
void inverse_matrix(int matrix[MAX][MAX], int r, int c) {

    if (r != 2 || c != 2) {
        printf("\n\033[0;31mThe matrix is not a square matrix, so the inverse of the matrix does not exist.\033[0;0m\n");
        return;
    }

    int determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    if (determinant == 0) {
        printf("\n\033[0;31mThe determinant of the matrix is 0, so the inverse of the matrix does not exist.\033[0;0m\n");
        return;
    }

    double inverse[MAX][MAX];

    inverse[0][0] = matrix[1][1] * (1.0 / determinant);
    inverse[0][1] = -matrix[0][1] * (1.0 / determinant);
    inverse[1][0] = -matrix[1][0] * (1.0 / determinant);
    inverse[1][1] = matrix[0][0] * (1.0 / determinant);

    for (int i = 0; i < 20; i++) {
        printf("\n");
    }

    printf("\n\033[0;32mThe determinant of the matrix is %d.\033[0;0m\n", determinant);

    printf("\nThe inverse of the matrix is:\n");
    printf("\t ");
    for (int k = 0; k < c; k++) {
        printf("\033[0;35m--------");
    }
    printf("\n");
    for (int i = 0; i < r; i++) {
        printf("\t|  ");
        for (int j = 0; j < c; j++) {
            printf("\033[0;0m%.1lf    \033[0;35m", inverse[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("\t ");
    for (int k = 0; k < c; k++) {
        printf("--------");
    }
    printf("\033[0;0m");
    printf("\n");
}


// Transpose of a matrix
void transpose_matrix(int matrix[MAX][MAX], int r, int c) {
    int transpose[MAX][MAX];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < 20; i++) {
        printf("\n");
    }

    printf("\nThe transpose of the matrix is:\n");
    printf("\t ");
    for (int k = 0; k < c; k++) {
        printf("\033[0;35m--------");
    }
    printf("\n");
    for (int i = 0; i < r; i++) {
        printf("\t|  ");
        for (int j = 0; j < c; j++) {
            printf("\033[0;0m%3d    \033[0;35m", transpose[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("\t ");
    for (int k = 0; k < c; k++) {
        printf("--------");
    }
    printf("\033[0;0m");
    printf("\n");
}
