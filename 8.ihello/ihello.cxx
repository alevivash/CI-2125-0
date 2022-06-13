///
/// ihello.cxx
///

/// Especificación por ejemplos:
///
/// ihello => "Hello, world!"
/// ihello en => "Hello, world!"
/// ihello sp => "Hola, mundo!"
/// ihello en Raimundo => "Hello, Raimundo!"
/// ihello sp Raimundo => "Hola, Raimundo!"
///
/// Deben incluir el encabezado que declara a strcmp
///
/// Recuerden chequear que
/// - el número de argumentos es consistente
/// - el código internacional del lenguaje esta soportado
///
/// Proveer mensajes de error infomación 
///
/// Implentar solo dos o tres lenguajes, para no alargar el código demasiado
///

#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{

  if (argc == 1)

  {

    printf("Hello world!\n");
  } 

   else if ((argc >=2 && argc <=3) && ((strcmp(argv[1], "en")) == 0 || (strcmp(argv[1], "sp")) == 0))

  {
    if (strcmp(argv[1], "en") == 0)
    
    {
        
    if (argv[2] != NULL)
        printf("Hello %s!\n", argv[2]);    
    else
        printf("Hello world!\n");
        
    } 
    
    else if (strcmp(argv[1], "sp") == 0) 
    
    {
        
    if (argv[2] != NULL)
        printf("Hola %s!\n", argv[2]);    
    else
        printf("Hola mundo!\n");    

    }

    return 0;

  } 

  else

  {
      
    fprintf(stderr, "uso: %s <<< incompleto >>>\n", argv[0]);
    return 1;
    
  }
}
