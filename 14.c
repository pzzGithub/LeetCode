//
// Created by 44811 on 2019/4/14.
//
#include <stdio.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    char *res = malloc(1000);
    int count = 0, i;
    while (strsSize > 0) {
        for (i = 1; i < strsSize; i++) {
            if (strs[0][count] != strs[i][count])
                break;
        }
        if (i == strsSize && strs[0][count] != '\0') {
            res[count] = strs[0][count];
            count++;
        } else
            break;
    }
    res[count++] = '\0';
    return res;
}

int main() {
    char *strs[3] = {"flower", "flow", "flight"};
    char *s = longestCommonPrefix(strs, 3);
    printf("%s", s);
    return 0;
}