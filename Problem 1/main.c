#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    const int upperBound = 1000;
    int count = 0;
    int i;
    for (i = 1; i < upperBound; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            count += i;
        }
    }
    printf("Solution: %d.\n", count);
    return EXIT_SUCCESS;
}
