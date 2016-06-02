#include <stdlib.h>
#include <stdio.h>

int isPalindrome(int i);

int main(int argc, char *argv[]) {
    const int digits = 1e3;
    int i, j, product, largest = -1;
    for (i = digits; i > 0; i--) {
        for (j = digits; j > 0; j--) {
            product = i * j;
            if (isPalindrome(product) && product > largest) {
                largest = product;
            }
        }
    }
    printf("Solution: %d.\n", largest);
    return EXIT_SUCCESS;
}

int reverse(int i) {
    int n = 0;
    while (i) {
        n = (n * 10) + (i % 10);
        i /= 10;
    }
    return n;
}

int isPalindrome(int i) {
    return i == reverse(i);
}
