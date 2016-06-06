#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int isPrime(unsigned int);

int main(int argc, char *argv[]) {
    const int limit = 2e6;
    long sum = 0;
    int i;
    for (i = 2; i < limit; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    printf("Solution: %ld.\n", sum);
    return EXIT_SUCCESS;
}

int isPrime(unsigned int n) {
    if (n == 0 || n == 1) {
        return -1;
    } else if (n == 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    }
    const int limit = sqrt(n);
    int i;
    for (i = 2; i <= limit; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
