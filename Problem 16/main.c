#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * This is definitely not how this was intended to be solved.
 */
int main(int argc, char *argv[]) {
    char digits[303] = { 0 };
    snprintf(digits, 303, "%lf", pow(2, 1000));
    int i, sum = 0;
    for (i = 0; i < 302; i++) {
        sum += digits[i] - '0';
    }
    printf("Solution: %d.\n", sum);
    return EXIT_SUCCESS;
}
