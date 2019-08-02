//
// Created by 44811 on 2019/4/20.
//
#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize) {
    if (numsSize <= 1)
        return numsSize;
    int i = 0, j, count = 1;
    while (i < numsSize) {
        j = i + 1;
        while (j < numsSize && nums[i] == nums[j]) {
            j++;
        }
        if (j < numsSize)
            nums[count++] = nums[j];
        i = j;
    }
    return count;
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 3, 4};
    int numsSize = 7;
    numsSize = removeDuplicates(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}