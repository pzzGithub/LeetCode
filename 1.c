#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target);

int main() {
    int nums[] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;
    int *res = twoSum(nums, numsSize, target);
    for (int i = 0; i < 2; i++) {
        printf("%d ", *(res + i));
    }
}


int *twoSum(int *nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int *a = malloc(2 * sizeof(int));
                a[0] = i;
                a[1] = j;
                return a;
            }
        }
    }
    return NULL;
}



