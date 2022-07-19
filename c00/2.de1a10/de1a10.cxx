///
/// de1a10.cxx
///
/// Programa de ejemplo que cuenta 1 a 10
/// Muestra el uso de la instrucción while para iterar
///

#include <stdio.h>
#define N 10

int main(void)
{
  int i = 1;
  while (i <= 10) 
  {
    fprintf(stdout, "Numero: %d\n", i);
    i = i + 1;

    if (i == N)
    {
      printf("Este es la variable N, %i\n", i);
      return 0;
    }
    else
    {
      return 0;
    }
  }
  
}

// Ejercicio: definir una constante entera N para el numero 10
