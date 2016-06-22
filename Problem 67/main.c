#include <stdlib.h>
#include <stdio.h>

#define MAX(A, B)   (((A) > (B)) ? (A) : (B))

int** readTriangle(FILE *, int *);
void freeTriangle(int **, int);

int main(int argc, char *argv[]) {
    FILE *file = fopen("triangle.txt", "r");
    if (file == NULL) {
        return EXIT_FAILURE;
    }
    int rows;
    int **triangle = readTriangle(file, &rows);
    fclose(file);
    if (triangle == NULL) {
        return EXIT_FAILURE;
    }
    if (rows > 0) {
        int row, column, left, right;
        for (row = rows - 2; row >= 0; row--) {
            for (column = 0; column <= row; column++) {
                left  = triangle[row + 1][column];
                right = triangle[row + 1][column + 1];
                triangle[row][column] += MAX(left, right);
            }
        }
        printf("Solution: %d.\n", triangle[0][0]);
    }
    freeTriangle(triangle, rows);
    return EXIT_SUCCESS;
}

int **readTriangle(FILE *file, int *rows) {
    fseek(file, 0, SEEK_END);
    int length = ftell(file), fileIndex = 0, limit = 3;
    *rows = 0;
    if (length >= limit) {
        while (fileIndex < length) {
            fileIndex += limit;
            limit += 3;
            (*rows)++;
        }
    }
    int **triangle = malloc(sizeof(*triangle) * (*rows));
    if (triangle == NULL) {
        return NULL;
    }
    rewind(file);
    char number[3] = { 0 };
    int i, j;
    for (i = 0; i < *rows; i++) {
        triangle[i] = malloc(sizeof(**triangle) * (i + 1));
        if (triangle[i] == NULL) {
            freeTriangle(triangle, i);
            return NULL;
        }
        for (j = 0; j <= i; j++) {
            if (fread(number, 1, 2, file) != 2) {
                freeTriangle(triangle, i + 1);
                return NULL;
            }
            fseek(file, 1, SEEK_CUR);
            triangle[i][j] = atoi(number);
        }
    }
    return triangle;
}

void freeTriangle(int **triangle, int rows) {
    while (--rows >= 0) {
        free(triangle[rows]);
    }
    free(triangle);
}
