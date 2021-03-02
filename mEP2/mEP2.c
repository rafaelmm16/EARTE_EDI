#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x0 = 0, x1 = 0;
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
    for (i = 0; i < ordem; i++)
    {
        x0 = 0;
        x1 = 0;
        for (j = 0; j < ordem; j++)
        {
            if (matrizB[i][j] == 0)
            {
                x0++;

                //Calculo da matriz C
                for (i = 0; i < ordem; i++)
                {
                    for (j = 0; j < ordem; j++)
                    {
                        matrizC[i][j] = matrizB[i][j] * VetPerm[i];
                    }
                }
            }
            else if (matrizB[i][j] == 1)
            {
                x1++;

                //Calculo da matriz C
                for (i = 0; i < ordem; i++)
                {
                    for (j = 0; j < ordem; j++)
                    {
                        matrizC[i][j] = matrizB[i][j] * VetPerm[i];
                    }
                }
            }
        }
    }

    for (j = 0; j < ordem; j++)
    {
        x0 = 0;
        x1 = 0;
        for (i = 0; i < ordem; i++)
        {
            if (matrizB[i][j] == 0)
            {
                x0++;
                //Calculo da matriz C
                for (i = 0; i < ordem; i++)
                {
                    for (j = 0; j < ordem; j++)
                    {
                        matrizC[i][j] = matrizB[i][j] * VetPerm[i];
                    }
                }
            }
            else
            {
                if (matrizB[i][j] == 1)
                {
                    x1++;
                    //Calculo da matriz C
                    for (i = 0; i < ordem; i++)
                    {
                        for (j = 0; j < ordem; j++)
                        {
                            matrizC[i][j] = matrizB[i][j] * VetPerm[i];
                        }
                    }
                }
            }
        }
    }

    //printf("A matriz e de permutacao\n");

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
    matrizB = NULL;
    return 0;
}