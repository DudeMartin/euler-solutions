#include <stdlib.h>
#include <stdio.h>

#define JANUARY 1
#define DECEMBER 12

int monthLength(int, int);

int main(int argc, char *argv[]) {
    int day = 6, month = JANUARY, year = 1901, sundays = 0;
    while (year <= 2000) {
        if (day == 1) {
            sundays++;
        }
        int remaining = monthLength(month, year) - day;
        if (remaining >= 7) {
            day += 7;
        } else {
            day = 7 - remaining;
            if (++month > DECEMBER) {
                month = JANUARY;
                year++;
            }
        }
    }
    printf("Solution: %d.\n", sundays);
    return EXIT_SUCCESS;
}

int isLeapYear(int year) {
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

int monthLength(int month, int year) {
    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return 28 + isLeapYear(year);
        default:
            return 31;
    }
}
