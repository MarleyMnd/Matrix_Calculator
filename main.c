//
// Created by Marley on 24/04/2023.
//

#include <stdio.h>
#include "functions.h"

#define MAX 100

int main() {
    int r, c;

    printf("                              \033[0;31m Matrix Calculator \033[0;0m\n\n");
    printf("This program can add, subtract, multiply or transpose any given matrices.\n\n");
    printf("Please enter the number of rows and columns of the your initial matrix.\n");
    printf("\tRows: ");
    scanf_s("%d", &r);
    printf("\tColumns: ");
    scanf_s("%d", &c);
    printf("\n");

    int matrix[MAX][MAX];

    printf("Please enter the values of the matrix.\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("\tValue at \033[0;32m(%d;%d)\033[0;0m: ", i + 1, j + 1);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < 20; i++) {
        printf("\n");
    }

    printf("\nYour matrix is:\n\n");
    printf("\t ");
    for (int k = 0; k < c; k++) {
        printf("\033[0;35m--------");
    }
    printf("\n");
    for (int i = 0; i < r; i++) {
        printf("\t|  ");
        for (int j = 0; j < c; j++) {
            printf("\033[0;0m%3d    \033[0;35m", matrix[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("\t ");
    for (int k = 0; k < c; k++) {
        printf("--------");
    }
    printf("\033[0;0m");

    // Print a menu
    printf("\n\n\nPlease select an option from the menu below:\n\n");
    printf("   \033[0;33m1.\033[0;0m Add two matrices.\n");
    printf("   \033[0;33m2.\033[0;0m Subtract two matrices.\n");
    printf("   \033[0;33m3.\033[0;0m Multiply two matrices.\n");
    printf("   \033[0;33m4.\033[0;0m Transpose of the matrix.\n");
    printf("   \033[0;33m5.\033[0;0m Inverse of the matrix.\n");
    printf("   \033[0;33m6.\033[0;0m Exit.\n\n");
    printf("Option: ");
    
    int option;

    scanf_s("%d", &option);

    switch (option) {
        case 1:
            add_matrices(matrix, r, c);
            break;
        case 2:
            subtract_matrices(matrix, r, c);
            break;
        case 3:
            multiply_matrices(matrix, r, c);
            break;
        case 4:
            transpose_matrix(matrix, r, c);
            break;
        case 5:
            inverse_matrix(matrix, r, c);
            break;
        case 6:
            printf("Thank you for using the Matrix Calculator!\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }

    return 0;
}