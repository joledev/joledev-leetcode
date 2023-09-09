#include <stdio.h>
#include <stdlib.h> // Include the necessary header file

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            int* result = malloc(2 * sizeof(int));
            result[0] = left;
            result[1] = right;
            *returnSize = 2;
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    int* result = twoSum(nums, numsSize, target, &returnSize);
    
    if (result != NULL) {
        printf("[%d, %d]\n", result[0], result[1]);
        free(result);
    }
    
    return 0;
}
