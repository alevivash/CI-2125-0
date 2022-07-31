///
/// matrix.cxx
///

#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

typedef double (*Initializer)(int i);

struct Matrix {
  double **data;
  size_t NR;
  size_t NC;
};

Matrix *matrix(size_t NR, size_t NC, Initializer init) {
  Matrix *result = (Matrix *) malloc(sizeof(Matrix));
  result->NR = NR;
  result->NC = NC;
  result->data = (double **) malloc(NR * sizeof(double *));
  for (size_t i = 0; i < NR; ++i) {
    result->data[i] = (double *) malloc(NC * sizeof(double));
    for (size_t j = 0; j < NC; ++j) {
      result->data[i][j] = init(NC * i + j);
    }
  }
  return result;
}

void matrix_destroy(Matrix **matrix) {
  size_t NR = (*matrix)->NR;
  for (size_t i = 0; i < NR; ++i) {
    free((*matrix)->data[i]);
    (*matrix)->data[i] = nullptr;
  }
  free((*matrix)->data);
  (*matrix)->data = nullptr;
  free(*matrix);
  *matrix = nullptr;
}

const double **matrix_data(const Matrix *matrix) {
  return (const double **) matrix->data;
}

size_t matrix_nr(const Matrix *matrix) {
  return matrix->NR;
}

size_t matrix_nc(const Matrix *matrix) {
  return matrix->NC;
}

Matrix *matrix_sum(const Matrix *lhs, const Matrix *rhs) {
  size_t LNR = lhs->NR;
  size_t LNC = lhs->NC;
  size_t RNR = rhs->NR;
  size_t RNC = rhs->NC;
  // if lhs and rhs are not conformant, print error and return null
  if (LNR != RNR || LNC != RNC) {
    fprintf(stderr, "Error: matrices que no tienen la misma forma no pueden ser sumadas: ");
    fprintf(stderr, "(%zux%zu) != (%zux%zu)\n", LNR, LNC, RNR, RNC);
    return nullptr;
  }
  Matrix *result = (Matrix *) malloc(sizeof(Matrix));
  result->NR = LNR;
  result->NC = LNC;
  result->data = (double **) malloc(LNR * sizeof(double *));
  for (size_t i = 0; i < LNR; ++i) {
    result->data[i] = (double *) malloc(LNC * sizeof(double));
    for (size_t j = 0; j < LNC; ++j) {
      result->data[i][j] = lhs->data[i][j] + rhs->data[i][j];
    }
  }
  return result;
}

Matrix *matrix_mult(const Matrix *lhs, const Matrix *rhs) {
  size_t LNR = lhs->NR; //Numero de filas de la matriz de la izquerda
  size_t LNC = lhs->NC; //numero de columnas de la matriz de la izquierda
  size_t RNR = rhs->NR; //numero de filas de la matriz de la derecha
  size_t RNC = rhs->NC; //numero de columnas de la matriz de la derecha

  if (LNC != RNR) {
  fprintf(stderr, "Error: el numero de columnas de la primmera matriz debe tener el mismo numero filas de la segunda matriz: ");
  fprintf(stderr, "(%zu) != (%zu)\n", LNC, RNR);
  return nullptr;
  }

  Matrix *result = (Matrix *) malloc(sizeof(Matrix));
  result->NR = LNR;
  result->NC = LNC;
  result->data = (double **) malloc(LNR * sizeof(double *));

  for (size_t i = 0; i < LNR; ++i) {
    for (size_t j = 0; j < RNC; ++j) {
      result->data[i] = (double *) malloc(LNC * sizeof(double));
      for(size_t k = 0; k < LNC; ++k){
        result->data[i][j] = ((lhs->data[i][k]) * (rhs->data[k][j]));
      }
    }
  }
  return result;
}
