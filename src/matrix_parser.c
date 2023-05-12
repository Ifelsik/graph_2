//
// Created by misha on 23.04.2023.
//

#include "../include/matrix_parser.h"

int getMatrixSize(char **matrix) {
    int matrix_size = 0;
    int row_len = 0;
    char *mcpy = NULL;
    char *row = NULL;

    while ((*matrix)[row_len] != '\0') {
        row_len++;
    }
    row_len++;

    row = (char*) malloc(sizeof(char) * row_len);
    if (NULL == row) {
        fprintf(stderr, "ERROR: can't allocate memory for 'row'\n");
        exit(1);
    }
    mcpy = (char*) malloc(sizeof(char) * row_len);
    if (NULL == mcpy) {
        fprintf(stderr, "ERROR: can't allocate memory for 'mcpy'\n");
        exit(1);
    }
    strcpy(mcpy, *matrix);
    row = strtok(mcpy, " ");
    while (row != NULL) {
        matrix_size++;
        row = strtok(NULL, " ");
    }
    free(row);
    return matrix_size;
}

int** parseSquareMatrix(char **matrix) {
    int row_len = 0;
    int matrix_size = getMatrixSize(matrix);
    char *row = NULL;
    int **parsed_matrix = NULL;
    
    parsed_matrix = (int**) malloc(sizeof(int*) * matrix_size);
    if (NULL == parsed_matrix) {
        fprintf(stderr, "ERROR: can't allocate memory for 'parsed matrix'\n");
        exit(1);
    }

    while ((*matrix)[row_len] != '\0') {
        row_len++;
    }

    if (matrix == NULL || *matrix == NULL) {
        fprintf(stderr, "ERROR: 'matrix' is empty\n");
        exit(1);
    }

    for(int i = 0; i < matrix_size; i++) {
        char* matrix_row_copy = NULL;
        int j = 0;
        parsed_matrix[i] = (int*) malloc(sizeof(int) * matrix_size);
        if (NULL == parsed_matrix[i]) {
            fprintf(stderr, "ERROR: can't allocate memory for 'parsed_matrix[i]'\n");
            exit(1);
        }

        row = (char*) malloc(sizeof(char) * row_len);
        matrix_row_copy = (char*) malloc(sizeof(char) * row_len);
        if (NULL == matrix_row_copy) {
            fprintf(stderr, "ERROR: can't allocate memory for 'matrix_row_copy'\n");
            exit(1);
        }

        strcpy(matrix_row_copy, matrix[i]);
        row = strtok(matrix_row_copy, " ");
        while (row != NULL) {
            parsed_matrix[i][j] = atoi(row);
            row = strtok(NULL, " ");
            j++;
        }
        free(matrix_row_copy);
        free(row);
    }
    return parsed_matrix;
}