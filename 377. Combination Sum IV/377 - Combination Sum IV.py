class Solution:
    def combinationSum4(self, nums, target):
        # Inicializamos un array dp con 0 en todas las posiciones hasta el objetivo target.
        dp = [0] * (target + 1)
        # Establecemos la primera posición del array como 1, ya que hay una combinación para alcanzar el objetivo 0 (ningún elemento).
        dp[0] = 1
        
        # Iteramos sobre cada valor desde 1 hasta target.
        for i in range(1, target + 1):
            # Iteramos sobre cada elemento num en nums.
            for num in nums:
                # Verificamos si el elemento num es menor o igual al valor actual i y si la resta i - num es mayor o igual a 0.
                if i >= num and i - num >= 0:
                    # Actualizamos dp[i] sumando las combinaciones de dp[i - num].
                    dp[i] += dp[i - num]
        
        # Retornamos el número de combinaciones para alcanzar el objetivo target.
        return dp[target]

# Creamos una instancia de la clase Solution.
s = Solution()

# Definimos los valores de entrada para las pruebas.
nums1 = [1, 2, 3]
target1 = 4

nums2 = [9]
target2 = 3

# Probamos la función con los valores dados.
output1 = s.combinationSum4(nums1, target1)
output2 = s.combinationSum4(nums2, target2)

# Imprimimos los resultados.
print(output1)  # Output: 7
print(output2)  # Output: 0
