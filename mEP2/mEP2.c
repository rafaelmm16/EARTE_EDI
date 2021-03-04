#include <stdio.h>
#include <stdlib.h>

//Funcao testa se e permutacao//

int permutacao(int **mat, int i, int j, int somai[], int somaj[])

{

    int x, y, per = 1;

    for (x = 0; x < i; x++)

        if (somai[x] != 1 || somaj[x] != 1)

            per = 0;

    return (per);
}

int main()
{
    int i = 0, j = 0;
    int ordem = 0;
    int **matrizB;
    int matrizC[ordem][ordem];
    int matrizA[ordem][ordem];
    int *VetPerm;
    int somaprod = 0;

    printf("ordem:\n");
    scanf("%d", &ordem);

    //Alocação do vetor de permutação
    VetPerm = malloc(ordem * sizeof(int));
    if (VetPerm == NULL)
    {
        printf("Sem memória \n");
        exit(1);
    }

    //vetor de permutação
    printf("permutacao\n");
    for (i = 0; i < ordem - 1; i++)
    {
        scanf("%d ", &VetPerm[i]);
        //printf("[%d]=%d\n", i, ordem);
    }

    //Alocação da matriz B
    matrizB = malloc(ordem * sizeof(int *));
    for (i = 0; i < ordem; i++)
    {
        matrizB[i] = malloc(ordem * sizeof(int));
    }

    //Leitura da matriz B
    printf("matriz B:\n");
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            scanf("%d ", matrizB[i]);
        }
    }

    //Matriz de Permutação

    //Calculo da matriz C
    /*
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            somaprod = 0;
            for (i = 0; i < ordem; i++)
            {
                somaprod += matrizA[i][i] * matrizB[i][j];
                matrizC[i][j] = somaprod;
            }
            //matrizC[i][j] = *matrizB[i] * VetPerm[i];
        }
    }
    */

    //Impressão da matriz C
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            printf("%d ", matrizC[i][j]);
        }
        printf("\n");
    }

    //permutacao(matrizB, i, j, matrizA, matrizC);

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