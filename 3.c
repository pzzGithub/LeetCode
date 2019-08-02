//
// Created by 44811 on 2019/4/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    char hash[130] = {0};
    int i = 0, n = 0, max_n = 1;
    if (strcmp(s, "") == 0)
        return 0;
    for (i = 0; i < strlen(s); i++) {
        if (hash[s[i]] == 0) {
            n++;
            hash[s[i]] = i + 1;
        } else {
            i = hash[s[i]] - 1;
            n = 0;
            memset(hash, 0, sizeof(hash));
        }
        if (n >= max_n)
            max_n = n;
    }
    return max_n;
}

int main() {
    char str[] = "abcabcbb";
    int x = lengthOfLongestSubstring(str);
    printf("%d", x);
    return 0;
}
