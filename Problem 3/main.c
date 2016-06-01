#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    const unsigned long given = 600851475143;
    unsigned long number = given, factor = 2, largest = factor;
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
    printf("Largest prime factor of %lu is: %lu.\n", given, largest);
    return EXIT_SUCCESS;
}
