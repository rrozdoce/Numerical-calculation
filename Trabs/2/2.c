#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
 Resolução de sistemas lineares pelo método de Gauss Seidel

  Entrada:
   -ordem da matriz (máximo 10) dos coeficientes das incógintas
   -Sistema linear
   -Precisão
   -Solução inicial

   Saida:
    -Resultados de cada passo (sistema e erro) com 8 casas decimais
    -Solução
    -Tempo de execução
*/

int main(int argc, char const *argv[])
{
    time_t start, end;
    int ordem = 0;
    float *sistema_linear;

    do
    {
        printf("Ordem:\n");
        scanf("%d", &ordem);

    } while (ordem > 10);

    sistema_linear = malloc(ordem * ordem * sizeof(float));
    start = time(NULL);
    time(&start);

    free(sistema_linear);

    time(&end);

    float time_taken = (double)start - (double)end;

    printf("Tempo de Execução: %lfs\n", time_taken);

    return 0;
}
