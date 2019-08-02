#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x);

int reverse(int x);

int main(int argc, char **argv) {
    int x = 10;
    int y = 2147483647;
    int z = 131;
    if (isPalindrome(x))
        printf("true\n");
    else
        printf("false\n");
    if (isPalindrome(y))
        printf("true\n");
    else
        printf("false\n");
    if (isPalindrome(z))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}

bool isPalindrome(int x) {
    if (x == 0)
        return true;
    else if (x < 0)
        return false;
    else
        return x == reverse(x);
}

int reverse(int x) {
    int y = 0;
    while (x != 0) {
        if (y > INT_MAX / 10 || y < INT_MIN / 10)
            return 0;
        y = x % 10 + y * 10;
        x = x / 10;
    }
    return y;
}
