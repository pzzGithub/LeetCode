//
// Created by 44811 on 2019/4/21.
//
#include <stdio.h>
#include <stdlib.h>

int searchInsert(int *nums, int numsSize, int target) {
    int index = 0;
    while (index < numsSize) {
        if (nums[index] == target)
            break;
        if (index == numsSize - 1 && nums[index] < target) {
            index++;
            break;
        }
        if (target < nums[0])
            break;
        if (nums[index] < target && nums[index + 1] > target) {
            index++;
            break;
        }
        index++;
    }
    return index;
}

int main() {
    int nums[4] = {1, 3, 4, 6};
    int target = 7;
    int numsSize = 4;
    int index = searchInsert(nums, numsSize, target);
    printf("%d", index);
}
