#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char *s);

int getNumber(char romanNum);

int main() {
    char *s = "MCMXCIV";
    int res = romanToInt(s);
    printf("%d", res);
}

int romanToInt(char *s) {
    char *p = s;
    int sum = 0;
    while (*p != NULL) {
        if (*p == 'I' && (*(p + 1) == 'V' || *(p + 1) == 'X')) {
            sum += getNumber(*(p + 1)) - getNumber(*p);
            p = p + 2;
        } else if (*p == 'X' && (*(p + 1) == 'L' || *(p + 1) == 'C')) {
            sum += getNumber(*(p + 1)) - getNumber(*p);
            p = p + 2;
        } else if (*p == 'C' && (*(p + 1) == 'D' || *(p + 1) == 'M')) {
            sum += getNumber(*(p + 1)) - getNumber(*p);
            p = p + 2;
        } else {
            sum += getNumber(*p);
            p++;
        }
    }
    return sum;
}

int getNumber(char romanNum) {
    if (romanNum == 'I')
        return 1;
    if (romanNum == 'V')
        return 5;
    if (romanNum == 'X')
        return 10;
    if (romanNum == 'L')
        return 50;
    if (romanNum == 'C')
        return 100;
    if (romanNum == 'D')
        return 500;
    if (romanNum == 'M')
        return 1000;
    else
        return 0;
}

