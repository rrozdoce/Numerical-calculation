#include <stdio.h>

int main()
{
  int i, j, k, n;
  double matriz[10][10], c, x[10], soma = 0.0;
  printf("\nEscreva a ordem da Matriz: ");
  scanf("%d", &n);
  printf("\nEscreva os elementos da matriz aumentada: \n\n");

  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      printf("MATRIZ[%i][%i]: ", i, j);
      scanf("%lf", &matriz[i][j]);
    }
  }
  for (j = 1; j <= n; j++)
  {
    for (i = 1; i <= n; i++)
    {
      if (i > j)
      {
        c = -(matriz[i][j] / matriz[j][j]);
        for (k = 1; k <= n + 1; k++)
        {
          matriz[i][k] = c * matriz[j][k] + matriz[i][k];
        }
      }
    }
  }

  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n + 1; j++)
    {
      if (j != n + 1)
      {
        printf("%0.2lf", matriz[i][j]);
      }
      else
      {
        printf("%0.2lf\n", matriz[i][j]);
      }
    }
    printf("\n");
  }

  x[n] = matriz[n][n + 1] / matriz[n][n];

  for (i = n - 1; i >= 1; i--)
  {
    soma = 0;
    for (j = i + 1; j <= n; j++)
    {
      soma = soma + matriz[i][j] * x[j];
    }
    x[i] = (matriz[i][n + 1] - soma) / matriz[i][i];
  }

  printf("\nA solucao eh: \n");

  for (i = 1; i <= n; i++)
  {
    printf("\nx%d=%lf\t", i, x[i]);
  }

  return 0;
}
