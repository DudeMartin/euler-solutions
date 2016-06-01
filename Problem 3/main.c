#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    const long given = 600851475143;
    long number = given, factor = 2, largest = factor;
    while (factor <= number) {
        if (number % factor == 0) {
            if (factor > largest) {
                largest = factor;
            }
            number /= factor;
            factor = 2;
        } else {
            factor++;
        }
    }
    printf("Largest prime factor of %ld is: %ld.\n", given, largest);
    return EXIT_SUCCESS;
}
