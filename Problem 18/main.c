#include <stdlib.h>
#include <stdio.h>

#define MAX(A, B)   (((A) > (B)) ? (A) : (B))

char** readTriangle(FILE *, int *);
void freeTriangle(char **, int);
int solveTriangle(char **, int, int, int);

int main(int argc, char *argv[]) {
    FILE *file = fopen("triangle.txt", "r");
    if (file == NULL) {
        return EXIT_FAILURE;
    }
    int rows;
    char **triangle = readTriangle(file, &rows);
    fclose(file);
    if (triangle == NULL) {
        return EXIT_FAILURE;
    }
    if (rows > 0) {
        printf("Solution: %d.\n", solveTriangle(triangle, 0, 0, rows));
    }
    freeTriangle(triangle, rows);
    return EXIT_SUCCESS;
}

char **readTriangle(FILE *file, int *rows) {
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
    char **triangle = malloc(sizeof(*triangle) * (*rows));
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

void freeTriangle(char **triangle, int rows) {
    while (--rows >= 0) {
        free(triangle[rows]);
    }
    free(triangle);
}

int solveTriangle(char **triangle, int row, int column, int rows) {
    int total = triangle[row][column];
    if (rows > 1) {
        if (row == rows - 2) {
            char left  = triangle[row + 1][column];
            char right = triangle[row + 1][column + 1];
            return total + MAX(left, right);
        }
        return total + MAX(solveTriangle(triangle, row + 1, column, rows), solveTriangle(triangle, row + 1, column + 1, rows));
    }
    return total;
}
