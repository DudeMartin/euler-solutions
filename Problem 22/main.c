#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **readNames(FILE *, int *);
void freeNames(char **, int);
int compareNames(const void *, const void *);

int main(int argc, char *argv[]) {
    FILE *f = fopen("names.txt", "r");
    if (f == NULL) {
        return EXIT_FAILURE;
    }
    int count;
    char **names = readNames(f, &count);
    fclose(f);
    if (names == NULL) {
        return EXIT_FAILURE;
    }
    qsort(names, count, sizeof(*names), compareNames);
    int i, j;
    unsigned long long namesScore = 0;
    for (int i = 0; i < count; i++) {
        char letter;
        int score = 0;
        for (j = 0; (letter = names[i][j]) != '\0'; j++) {
            score += letter - ('A' - 1);
        }
        namesScore += (i + 1) * score;
    }
    printf("Solution: %llu.\n", namesScore);
    freeNames(names, count);
    return EXIT_SUCCESS;
}

char **readNames(FILE *f, int *count) {
    rewind(f);
    *count = 0;
    int c;
    for (; (c = fgetc(f)) != EOF; (*count) += (c == ','));
    (*count) += (ftell(f) > 0);
    char **names = malloc(sizeof(*names) * (*count));
    if (names == NULL) {
        return NULL;
    }
    rewind(f);
    int i = 0, start = -1, end = -1;
    while (i < *count) {
        c = fgetc(f);
        if (c == '"') {
            if (start == -1) {
                start = ftell(f);
            } else if (end == -1) {
                end = ftell(f) - 1;
            }
        } else if (c == ',' || feof(f)) {
            int length = end - start;
            char *name = calloc(length + 1, 1);
            if (name == NULL) {
                freeNames(names, *count);
                return NULL;
            }
            if (fseek(f, start, SEEK_SET) != 0 || fread(name, 1, length, f) < length || fseek(f, 2, SEEK_CUR) != 0) {
                freeNames(names, *count);
                free(name);
                return NULL;
            }
            names[i++] = name;
            start = end = -1;
        }
    }
    return names;
}

void freeNames(char **names, int count) {
    while (--count >= 0) {
        free(names[count]);
    }
    free(names);
}

int compareNames(const void *a, const void *b) {
    return strcmp(*((const char **) a), *((const char **) b));
}
