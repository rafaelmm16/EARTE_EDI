#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x = 0;
    int i = 0, j = 0;
    int ordem = 0;
    int matrizA[ordem][ordem];
    int **matrizB;
    int matrizC[ordem][ordem];
    int VetPerm[ordem];

    scanf("%d", &ordem);

    //vetor de permutação
    for (i = 0; i < ordem; i++)
    {
        scanf("%d ", &VetPerm[i]);
    }

    /*matriz A
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            scanf("%d", &matrizA[i][j]);
        }
    }
    */

    //matriz B
    matrizB = malloc(ordem * sizeof(int *));
    for (i = 0; i < ordem; i++)
    {
        matrizB[i] = malloc(ordem * sizeof(int));

        scanf("%d ", matrizB[i]);
    }

    free(matrizB);
    return 0;
}