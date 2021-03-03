#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0, j = 0;
    int ordem = 0;
    int **matrizB;
    int matrizC[ordem][ordem];
    int *VetPerm;

    scanf("%d", &ordem);

    //Alocação do vetor de permutação
    VetPerm = malloc(ordem * sizeof(int));
    //vetor de permutação
    for (i = 0; i < ordem; i++)
    {
        scanf("%d ", &VetPerm[i]);
    }

    //matriz B
    matrizB = malloc(ordem * sizeof(int *));
    for (i = 0; i < ordem; i++)
    {
        matrizB[i] = malloc(ordem * sizeof(int));

        scanf("%d ", matrizB[i]);
    }

    //Matriz de Permutação

    //Calculo da matriz C
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            matrizC[i][j] = matrizB[i][j] * VetPerm[i];
        }
    }

    //Impressão da matriz C
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            printf("%d ", matrizC[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < ordem; i++)
    {
        free(matrizB[i]);
        matrizB[i] = NULL;
    }
    free(matrizB);
    free(VetPerm);
    matrizB = NULL;
    return 0;
}