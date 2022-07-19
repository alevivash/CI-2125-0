///
/// suma1aN.cxx
///
/// Ejercicio de evaluación
///
/// calcular suma(i = 1 .. N, i) donde N es pasado como argumento
///

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{

    int n = atoi(argv[1]);
    
    int sumatoria = (n * (n + 1)) / 2;
    printf("La suma de los %s números naturales es igual a %i\n\n", argv[1], sumatoria);
    
}
