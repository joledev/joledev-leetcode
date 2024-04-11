<?php
class Solution
{
  /**
   * Función que calcula el número de combinaciones posibles para alcanzar el objetivo utilizando los números dados.
   *
   * @param Integer[] $nums Un array de números enteros.
   * @param Integer $target El objetivo al que se quiere llegar.
   * @return Integer El número de combinaciones posibles.
   */
  function combinationSum4($nums, $target)
  {
    // Creamos un array $dp para almacenar el número de combinaciones posibles para cada valor desde 0 hasta el objetivo $target.
    $dp = array_fill(0, $target + 1, 0);
    // Inicializamos la primera posición del array como 1, ya que hay una combinación para alcanzar el objetivo 0 (ningún elemento).
    $dp[0] = 1;

    // Iteramos sobre cada valor desde 1 hasta $target.
    for ($i = 1; $i <= $target; $i++) {
      // Iteramos sobre cada elemento $num en $nums.
      foreach ($nums as $num) {
        // Verificamos si el elemento $num es menor o igual al valor actual $i.
        if ($i >= $num) {
          // Actualizamos $dp[$i] sumando las combinaciones de $dp[$i - $num].
          $dp[$i] += $dp[$i - $num];
        }
      }
    }

    // Retornamos el número de combinaciones para alcanzar el objetivo $target.
    return $dp[$target];
  }
}

// Creamos una instancia de la clase Solution.
$r = new Solution;

// Datos de prueba y cálculo de los resultados.
$nums = [1,2,3];
$target = 4;
echo $r->combinationSum4($nums, $target) . PHP_EOL; // Output: 7

$nums = [9];
$target = 3;
echo $r->combinationSum4($nums, $target) . PHP_EOL; // Output: 0