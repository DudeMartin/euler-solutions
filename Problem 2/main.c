#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    const int upperBound = 4e6;
    int previous = 1, current = 2, sum = 0, temp;
    do {
        if (current % 2 == 0) {
            sum += current;
        }
        temp = current;
        current += previous;
        previous = temp;
    } while (current < upperBound);
    printf("Solution: %d.\n", sum);
    return EXIT_SUCCESS;
}
