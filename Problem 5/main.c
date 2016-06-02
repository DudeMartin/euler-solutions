#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int number = 40, i;
    while (1) {
        for (i = 2; i <= 20; i++) {
            if (number % i != 0) {
                break;
            }
        }
        if (i == 21) {
            break;
        }
        number += 20;
    }
    printf("Solution: %d.\n", number);
    return EXIT_SUCCESS;
}
