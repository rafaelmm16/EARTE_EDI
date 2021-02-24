#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x = 0;
    int i = 0, j = 0;
    int ordem = 0;
    int matrizA[ordem][ordem];
    int **matrizB;
    int VetPerm[ordem];

    scanf("%d", &ordem);

    //matriz A
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            scanf("%d", &matrizA[i][j]);
        }
    }

    //matriz B
    matrizB = malloc(ordem * sizeof(int *));
    for (i = 0; i < ordem; i++)
    {
        matrizB[i] = malloc(ordem * sizeof(int));
    }

    return 0;
}