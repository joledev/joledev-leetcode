#include <stdio.h>
#include <string.h>

int combinationSum4(int* nums, int numsSize, int target) {
  int dp[target + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;

  for (int i = 1; i <= target; i++) {
    for (int j = 0; j < target; j++) {
      if (i >= nums[j]) {
        dp[i] += dp[i - nums[j]];
      }
    }
  }

  return dp[target];
}

int main() {
  int nums[] = {1,2,3};
  int target = 4;
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int result = combinationSum4(nums, numsSize, target);
  printf("Output: %d\n", result);

  int nums2[] = {9};
  int target2 = 3;
  int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
  int result2 = combinationSum4(nums, numsSize2 , target2);
  printf("Output: %d\n", result2);

  return 0;
}
