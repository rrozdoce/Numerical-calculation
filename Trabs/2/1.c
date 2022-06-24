#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
  Cálculo de determinantes pelo método de Gauss com Pivotação Parcial

  Entrada:
    -ordem da matriz (Máximo 10)
    -Matriz
  Saida:
   -Resultados de cada passo com 2 casas decimais
   -Determinante
   -Tempo de execuçãos
*/

int main(int argc, char const *argv[])
{
  time_t start, end;
  int ordem = 0;
  float *matriz;

  do
  {
    printf("Ordem da Matriz:\n");
    scanf("%d", &ordem);

  } while (ordem > 10);

  matriz = malloc(ordem * ordem * sizeof(float));

  // resolucao
  start = time(NULL);
  time(&start);

  //

  free(matriz);

  time(&end);

  double time_taken = (double)end - (double)start;

  printf("Tempo de Execucao: %lfs\n", time_taken);

  return 0;
}
