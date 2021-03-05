#include <stdio.h>
#include <stdlib.h>

int menorV(int n, int vet[])
{
    int menor = 0;

    menor = vet[0];
    for (int i = 0; i < n; i++)
    {
        if (vet[i] < menor)
        {
            menor = vet[i];
        }
    }

    printf("Menor = %d", menor);
}

int main()
{
    int i = 0, j = 0;
    int ordem = 0;
    int max = 0;
    int **matrizB;
    int matrizC[ordem][ordem];
    int matrizA[ordem][ordem];
    //indica a linha onde tem o 1
    int *VetPerm; // posição e ordem de deslocação
    int somaprod = 0;

    printf("ordem:\n");
    scanf("%d", &ordem);

    //Alocação do vetor de permutação
    VetPerm = (int *)malloc(ordem * sizeof(int));
    if (VetPerm == NULL)
    {
        printf("Sem memória \n");
        exit(1);
    }

    //vetor de permutação
    printf("permutacao\n");
    for (i = 0; i < ordem; i++)
    {
        scanf("%d", &VetPerm[i]);
        //printf("[%d] = %d\n", i, VetPerm[i]);
    }

    //pega o menor elemento do vetor p
    menorV(ordem, VetPerm);

    //Alocação da matriz B
    matrizB = (int *)malloc(ordem * sizeof(int *));
    for (i = 0; i < ordem; i++)
    {
        matrizB[i] = (int *)malloc(ordem * sizeof(int));
    }

    //Leitura da matriz B
    printf("matriz B:\n");
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            scanf("%d", matrizB[i]);
        }
    }

    //matriz C
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
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