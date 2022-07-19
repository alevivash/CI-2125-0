///
/// suma1a10.cxx
///
/// Ejercicio: calcular suma(i = 1 .. 10, i)
///

#include <stdio.h>

int main()
{
  int resultado = 0;
  // ... sumar cada i al resultado

  resultado = ((10 * (10 + 1)) / 2); //Suma de Gauss

  fprintf(stdout, "suma(i = 1 .. 10, i) == %i\n", resultado);
  return 0;
}
