#include <stdlib.h>
#include <stdio.h>

unsigned long long paths(int, int);

/*
 * Alternatively, this can be solved simply by evaluating
 * the expression: 40 choose 20.
 */
int main(int argc, char *argv[]) {
    printf("Solution: %llu.\n", paths(20, 20));
    return EXIT_SUCCESS;
}

unsigned long long paths(int x, int y) {
    if (y == 0) {
        return 1;
    } else if (y > 0 && y < x) {
        return paths(x, y - 1) + paths(x - 1, y);
    } else if (x == y) {
        return 2 * paths(x, y - 1);
    }
    return -1;
}
