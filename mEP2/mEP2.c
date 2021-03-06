#include <stdio.h>
#include <stdlib.h>

void imprimeLinha(int *linha, int tam) //recebe o ponteiro do vetor da linha, tamanho = n que o usuario digita
{
    for (int i = 0; i < tam; i++) //laço que percorre a linha da matriz
        printf("%d ", linha[i]);  // imprime os elementos da matriz
    printf("\n");
}

int main()
{
    int i = 0, j = 0;
    int ordem = 0;
    int **matrizB;
    int matrizC[ordem][ordem];
    int matrizA[ordem][ordem];
    int *VetPerm; // posição e ordem de deslocação

    scanf("%d", &ordem);

    //Alocação do vetor de permutação
    VetPerm = malloc(ordem * sizeof(int));
    if (VetPerm == NULL)
    {
        printf("Sem memória \n");
        exit(1);
    }

    //vetor de permutação
    for (i = 0; i < ordem; i++)
    {
        scanf("%d", &VetPerm[i]);
    }

    //Alocação da matriz B
    matrizB = malloc(ordem * sizeof(int *));
    for (i = 0; i < ordem; i++)
    {
        matrizB[i] = malloc(ordem * sizeof(int));
    }

    //Leitura da matriz B
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            scanf("%d", &matrizB[i][j]);
        }
    }

    //matriz C
    for (i = 1; i <= ordem; i++) //procura o primeiro elemento
    {
        for (j = 0; j < ordem; j++) // percorre o vetor procurando o indice
        {
            if (i == VetPerm[j]) //quando ele acha o indice IMPRIME a matriz
                imprimeLinha(matrizB[j], ordem);
        }
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