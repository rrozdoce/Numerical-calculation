// meu código c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int main()
{ 
    int cont_estados = 0;
    int cont_alfabeto = 0;
    int estado_inicial;
    int cont_estados_finais = 0;
    char transicoes[cont_estados][128];

    typedef struct
    {
        int estados[cont_estados];
        char alfabeto[cont_alfabeto];
    } estados;

    estados estados_iniciais;
    estados estados_finais;

    printf("Digite o numero de estados:\n");
    scanf("%d", &cont_estados);

    printf("Digite o número do estado inicial, indexado de 0 a n - 1: ");
    scanf("%d", &estado_inicial);

    printf("Digite o tamanho do alfabeto:\n");
    scanf("%d", &cont_alfabeto);

    printf("Digite o alfabeto:\n");
    for (int i = 0; i < cont_alfabeto; i++)
    {
        scanf("%c", &estados_iniciais.alfabeto[i]);
    }
    
    for(int i = 0; i < cont_estados; i++) {
        for(int j = 0; j < cont_alfabeto; j++) {
            printf("Estado q%i|%c|\n", cont_estados, estados_iniciais.alfabeto[j]);
            scanf("%c\n", &transicoes[j]);
        }
    }
    

    return 0;
}
