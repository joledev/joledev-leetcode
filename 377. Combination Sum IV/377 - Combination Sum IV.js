// Definimos una función llamada combinationSum4 que toma un array nums y un objetivo target como parámetros
var combinationSum4 = function (nums, target) {
  // Creamos un array llamado dp para almacenar el número de combinaciones posibles para cada valor desde 0 hasta el objetivo target
  const dp = new Array(target + 1).fill(0);
  dp[0] = 1; // Inicializamos la primera posición del array como 1, ya que hay una combinación para alcanzar el objetivo 0 (ningún elemento)

  // Iteramos sobre cada valor desde 1 hasta target
  for (let i = 1; i <= target; i++) {
    // Iteramos sobre cada elemento num en nums
    for (let num of nums) {
      // Verificamos si el elemento num es menor o igual al valor actual i
      if (num <= i) {
        // Actualizamos dp[i] sumando las combinaciones de dp[i - num]
        dp[i] += dp[i - num];
      }
    }
  }

  // Retornamos el número de combinaciones para alcanzar el objetivo target
  return dp[target];
};

// Datos de prueba
console.log("Case 1:");
console.log(combinationSum4([1, 2, 3], 4)); // Debe imprimir 7

console.log("Case 2:");
console.log(combinationSum4([9], 3)); // Debe imprimir 0
