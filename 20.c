//
// Created by 44811 on 2019/4/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool pp(char a, char b) {
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
        return true;
    else
        return false;
}

bool isValid(char *s) {
    int length = 0;
    while (1) {
        if (*(s + length) == '\0')
            break;
        length++;
    }
    char *stack = malloc(length + 1);
    memset(stack, 0, length + 1);
    int i = 0, j = 0;
    while (1) {
        if (i == length)
            break;
        if (pp(*(stack + j), *(s + i))) {
            j--;
            i++;
        } else {
            j++;
            *(stack + j) = *(s + i);
            i++;
        }
    }
    if (j == 0)
        return true;
    else
        return false;
}


int main() {
    char s[] = "(]";
    if (isValid(s))
        printf("true");
    else
        printf("false");
    return 0;
}
