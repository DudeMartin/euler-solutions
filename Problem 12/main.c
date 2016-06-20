#include <stdlib.h>
#include <stdio.h>

long long triangular(int);
int divisorCount(long long);

int main(int argc, char *argv[]) {
    int n = 0;
    while (divisorCount(triangular(n)) <= 500) {
        n++;
    }
    printf("Solution: %lld.\n", triangular(n));
    return EXIT_SUCCESS;
}

long long triangular(int n) {
    return (n * (n + 1)) / 2;
}

int divisorCount(long long n) {
    int divisors = 1;
    while (n > 1 && n % 2 == 0) {
        n /= 2;
        divisors++;
    }
    long long i;
    int count;
    for (i = 3, count = 1; i * i <= n; i += 2) {
        while (n > 1 && n % i == 0) {
            n /= i;
            count++;
        }
        divisors *= count;
        count = 1;
    }
    return (n > 1) ? (divisors * 2) : divisors;
}
