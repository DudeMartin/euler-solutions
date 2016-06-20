#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    unsigned long term, currentChain, n, longestChain = currentChain, longestTerm = 1;
    for (term = 2, currentChain = 1; term < 1000000; term++, currentChain = 1) {
        n = term;
        while (n != 1) {
            if (n % 2 == 0) n /= 2;
            else            n = 3 * n + 1;
            currentChain++;
        }
        if (currentChain > longestChain) {
            longestChain = currentChain;
            longestTerm = term;
        }
    }
    printf("Solution: %lu.\n", longestTerm);
    return EXIT_SUCCESS;
}
