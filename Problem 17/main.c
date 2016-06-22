#include <stdlib.h>
#include <stdio.h>

int numberLength(int);

int main(int argc, char *argv[]) {
    int number, sum = 0;
    for (number = 1; number <= 1000; number++) {
        sum += numberLength(number);
    }
    printf("Solution: %d.\n", sum);
    return EXIT_SUCCESS;
}

int numberLength(int n) {
    if (n <= 19) {
        switch (n) {
            case 0:
                /*
                 * Special case.
                 */
                return 0;
            case 1:
            case 2:
            case 6:
            case 10:
                return 3;
            case 4:
            case 5:
            case 9:
                return 4;
            case 3:
            case 7:
            case 8:
                return 5;
            case 12:
            case 11:
                return 6;
            case 15:
            case 16:
                return 7;
            case 13:
            case 14:
            case 18:
            case 19:
                return 8;
            case 17:
                return 9;
        }
    } else if (n <= 99) {
        switch (n) {
            case 20 ... 29:
                return 6 + numberLength(n - 20);
            case 30 ... 39:
                return 6 + numberLength(n - 30);
            case 40 ... 49:
                return 5 + numberLength(n - 40);
            case 50 ... 59:
                return 5 + numberLength(n - 50);
            case 60 ... 69:
                return 5 + numberLength(n - 60);
            case 70 ... 79:
                return 7 + numberLength(n - 70);
            case 80 ... 89:
                return 6 + numberLength(n - 80);
            case 90 ... 99:
                return 6 + numberLength(n - 90);
        }
    } else if (n <= 999) {
        int length = numberLength(n / 100) + 7;
        if (n % 100 != 0) {
            length += 3 + numberLength(n % 100);
        }
        return length;
    }
    return 11;
}
