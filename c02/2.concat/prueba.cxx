#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *concatenate(const char *lhs, const char *rhs) {
  size_t lsize = strlen(lhs);
  size_t rsize = strlen(rhs);
  
  char *result = (char * ) malloc((lsize + rsize + 1) * sizeof(char));
  strcpy(result,lhs);
  strcpy(&result[lsize],rhs);

  return result;
}

int main(void)
{
  const char* perro ="perro";
  const char* gato ="gato";
  
  const char* text1[] = {"arroz", "pasta", "carne", "fruta"};
  const char* text2[] = {"amarillo", "morado", "rojo", "azul"};

  const char *result  = concatenate(perro, gato);

  printf("%s", result);
}