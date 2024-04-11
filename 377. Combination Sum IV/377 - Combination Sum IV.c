#include <stdio.h>
#include <string.h>

int combinationSum4(int* nums, int numsSize, int target) {
  // Creamos un array llamado dp para almacenar el número de combinaciones posibles para cada valor desde 0 hasta el objetivo target
  int dp[target + 1];
  
  // Inicializamos todos los elementos del array dp con 0
  memset(dp, 0, sizeof(dp));
  
  // Establecemos la primera posición del array dp como 1, ya que hay una combinación para alcanzar el objetivo 0 (ningún elemento)
  dp[0] = 1;

  // Iteramos sobre cada valor desde 1 hasta target
  for (int i = 1; i <= target; i++) {
    // Iteramos sobre cada elemento num en nums
    for (int j = 0; j < numsSize; j++) {
      // Verificamos si el elemento num es menor o igual al valor actual i
      if (i >= nums[j]) {
        // Actualizamos dp[i] sumando las combinaciones de dp[i - nums[j]]
        dp[i] += dp[i - nums[j]];
      }
    }
  }

  // Retornamos el número de combinaciones para alcanzar el objetivo target
  return dp[target];
}

int main() {
  int nums[] = {1,2,3};
  int target = 4;
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int result = combinationSum4(nums, numsSize, target);
  printf("Output: %d\n", result); // Output: 7

  int nums2[] = {9};
  int target2 = 3;
  int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
  int result2 = combinationSum4(nums2, numsSize2, target2);
  printf("Output: %d\n", result2); // Output: 0

  return 0;
}
