#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * This solution uses Dickson's method for generating Pythagorean
 * triples.
 */
int main(int argc, char *argv[]) {
    int parameter, product, limit, factor, quotient, a, b, c;
    for (parameter = 1;; parameter++) {
        product = parameter * parameter / 2;
        limit = sqrt(product);
        for (factor = 1; factor <= limit; factor++) {
            if (product % factor == 0) {
                quotient = product / factor;
                a = parameter + factor;
                b = parameter + quotient;
                c = parameter + factor + quotient;
                if (a + b + c == 1000) {
                    printf("Solution: %d.\n", a * b * c);
                    return EXIT_SUCCESS;
                }
            }
        }
    }
    return EXIT_FAILURE;
}
