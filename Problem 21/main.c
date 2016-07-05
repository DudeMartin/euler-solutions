#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int sumDivisors(int);

int main(int argc, char *argv[]) {
    int i, sum = 0;
    for (i = 2; i < 10000; i++) {
        int b = sumDivisors(i);
        if (sumDivisors(b) == i && i < b) {
            sum += b + i;
        }
    }
    printf("Solution: %d.\n", sum);
    return EXIT_SUCCESS;
}

int sumDivisors(int n) {
    int i, sum = 0;
    for (i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            if (i > 1) {
                sum += n / i;
            }
        }
    }
    return sum;
}
