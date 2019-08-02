//
// Created by 44811 on 2019/4/20.
//

#include <stdio.h>
#include <stdlib.h>

int removeElement(int *nums, int numsSize, int val) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val)
            nums[count++] = nums[i];
    }
    return count;
}

int main() {
    int nums[] = {3, 2, 2, 3};
    int numsSize = 4;
    int val = 2;
    numsSize = removeElement(nums, numsSize, val);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
}