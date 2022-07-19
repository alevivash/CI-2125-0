///
/// hola.cxx
///
/// Ejercicio: completar el programa
///

#include <stdio.h>

int main(int argc, const char *argv[])
{
  if (argc == 1) {
    // ... imprimir "Hola!"
    fprintf(stdout, "Hola!\n");
    return 0;
  } else if (argc == 2) {
     // ... imprimir "Hola <nombre>!
    fprintf(stdout, "Hola %s\n", argv[1]);
    return 0;
  } else {
    fprintf(stderr, "uso: %s [<nombre>]\n", argv[0]);
    return 1;
  }
  return 0;
}

