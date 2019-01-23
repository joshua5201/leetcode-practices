#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int *resultNums = malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (i == j) {
                continue;
            }
            if (nums[i] + nums[j] == target) {
                resultNums[0] = i;
                resultNums[1] = j;
                break;
            }
        }
    }
    return resultNums;
}
