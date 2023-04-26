//
// Created by Marley on 24/04/2023.
//

#include <stdio.h>

// Define the maximum size of the matrix
#define MAX 100

/*
 *
 * ADDITION OF 2 MATRICES
 *
 * This function adds two matrices.
 * The matrices must have the same number of rows and columns.
 */
void add_matrices(int matrix[MAX][MAX], int r, int c) {
    int matrix2[MAX][MAX];

    // Enter the values of the second matrix
    printf("\nPlease enter the values of the second matrix.\n");
    printf("Note: The number of rows and columns must be the same as the first matrix \033[0;32m(%d x %d)\033[0;0m.\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("\tValue at \033[0;32m(%d;%d)\033[0;0m: ", i + 1, j + 1);
            scanf_s(" %d", &matrix2[i][j]);
        }
    }

    int sum[MAX][MAX];

    // Compute the sum of the two matrices
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }

    // Clear the screen
    for (int i = 0; i < 20; i++) {
        printf("\n");
    }

    // Display the sum of the two matrices
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


/*
 *
 * DIFFERENCE OF 2 MATRICES
 *
 * This function subtracts two matrices.
 * The matrices must have the same number of rows and columns.
 */
void subtract_matrices(int matrix[MAX][MAX], int r, int c) {
    int matrix2[MAX][MAX];

    // Enter the values of the second matrix
    printf("\nPlease enter the values of the second matrix.\n");
    printf("Note: The number of rows and columns must be the same as the first matrix \033[0;32m(%d x %d)\033[0;0m.\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("\tValue at \033[0;32m(%d;%d)\033[0;0m: ", i + 1, j + 1);
            scanf_s(" %d", &matrix2[i][j]);
        }
    }

    int sum[MAX][MAX];

    // Compute the difference of the two matrices
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = matrix[i][j] - matrix2[i][j];
        }
    }

    // Clear the screen
    for (int i = 0; i < 20; i++) {
        printf("\n");
    }

    // Display the difference of the two matrices
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

/*
 *
 * MULTIPLICATION OF 2 MATRICES
 *
 * This function multiplies two matrices.
 * /!\ The number of columns of the first matrix must be equal to the number of rows of the second matrix.
 */
void multiply_matrices(int matrix[MAX][MAX], int r1, int c1) {
    int matrix2[MAX][MAX];

    // Enter the values of the second matrix
    printf("\nPlease enter the values of the second matrix.\n");
    printf("Note: The number of rows and columns must be the same as the first matrix \033[0;32m(%d x %d)\033[0;0m.\n", c1, r1);
    for (int i = 0; i < c1; i++) {
        for (int j = 0; j < r1; j++) {
            printf("\tValue at \033[0;32m(%d;%d)\033[0;0m: ", i + 1, j + 1);
            scanf_s(" %d", &matrix2[i][j]);
        }
    }

    // Nb of rows of the second matrix = Nb of columns of the first matrix
    int r2 = c1;
    // Nb of columns of the second matrix = Nb of rows of the first matrix
    int c2 = r1;

    int product[MAX][MAX];

    // Compute the product of the two matrices
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++){
            product[i][j] = 0;
            for (int k = 0; k < r2; k++) {
                product[i][j] += matrix[i][k] * matrix2[k][j];
            }
        }
    }

    // Clear the screen
    for (int i = 0; i < 20; i++) {
        printf("\n");
    }

    // Display the product of the two matrices
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


/*
 *
 * INVERSE OF A 2x2 MATRIX
 *
 * This function finds the inverse of a 2x2 matrix.
 * The determinant of the matrix must not be equal to 0, otherwise the inverse of the matrix does not exist.
 */
void inverse_matrix(int matrix[MAX][MAX], int r, int c) {

    // Check if the matrix is a 2x2 matrix
    if (r != 2 || c != 2) {
        printf("\n\033[0;31mThis is not a \033[0;32m2x2\033[0;0m\033[0;31m matrix. This function is only available for \033[0;32m2x2\033[0;0m\033[0;31m matrices yet.\033[0;0m\n");
        return;
    }

    // Compute the determinant of the matrix
    int determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    // Check if the determinant is equal to 0, if so the inverse of the matrix does not exist
    if (determinant == 0) {
        printf("\n\033[0;31mThe determinant of the matrix is equal to 0, so the inverse of the matrix does not exist.\033[0;0m\n");
        return;
    }

    double inverse[MAX][MAX];

    // Compute the inverse of the matrix
    inverse[0][0] = matrix[1][1] * (1.0 / determinant);
    inverse[0][1] = -matrix[0][1] * (1.0 / determinant);
    inverse[1][0] = -matrix[1][0] * (1.0 / determinant);
    inverse[1][1] = matrix[0][0] * (1.0 / determinant);

    // Clear the screen
    for (int i = 0; i < 20; i++) {
        printf("\n");
    }

    // Display the determinant of the matrix
    printf("\n\033[0;32mThe determinant of the matrix is %d.\033[0;0m\n", determinant);

    // Display the inverse of the matrix
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


/*
 *
 * TRANSPOSE OF A MATRIX
 *
 * This function finds the transpose of a matrix.
 * The transpose of a matrix is the matrix obtained by turning all the rows of the matrix into columns and vice versa.
 */
void transpose_matrix(int matrix[MAX][MAX], int r, int c) {
    int transpose[MAX][MAX];

    // Compute the transpose of the matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Clear the screen
    for (int i = 0; i < 20; i++) {
        printf("\n");
    }

    // Display the transpose of the matrix
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
