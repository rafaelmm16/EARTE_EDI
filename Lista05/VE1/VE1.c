#include <stdio.h>
#include <stdlib.h>

#include "VE1.h"

struct ve1
{
    int capacidade; //Tamanho do array F
    int n;          //Posição do útimo elemento (também pode ser usado para determinar o #elementos)
    int *P;         //Array para armazenar os elementos na estrutura
};

VE1 *criaVE1(int capacidade)
{
    /*Verifique se o valor em capacidade é válido */
    /*Se for, inicialize n com -1 (indicando que a estrutura está vazia) */
    /*Aloque o array 'P' e retorne o ponteiro da estrutura */

    struct ve1 *VE1;

    /*if (VE1 == NULL)
    {
        printf("Sem memoria");
        exit(1);
    }
    else
    {*/
    VE1 = malloc(sizeof(int));

    VE1->n = -1;
    //}
    if (VE1->P == NULL)
    {
        printf("Sem memoria");
        exit(1);
    }
    else
    {
        VE1->P = (int *)malloc(capacidade * sizeof(int));
        printf("Chega\n");
    }

    return VE1;
}

void liberaVE1(VE1 *ve)
{
    /* Faz a desalocação de memória */
    if (ve != NULL)
    {
        ve = NULL;
        free(ve);
    }
}

void adicionaVE1(VE1 *ve, int v)
{
    /* Adiciona um elemento no fim do vetor */
    /* Lembre-se de verificar se há espaço para adicionar o elemento */
    /* Complexidade: O(???)  */

    int i = 0;
    struct ve1 *v1;

    v1 = malloc(sizeof(int));

    for (i = 0; i > v1->capacidade; i--)
    {
        if (ve < v1->capacidade)
        {
            ve[i] = ve[v];
            printf("Preencheu %d\n", ve[i]);
        }
    }
}

void removeVE1(VE1 *ve)
{
    /* Retira o ultimo elemento*/
    /* Complexidade: O(???)  */

    int i = 0;
    struct ve1 *v1;

    v1 = malloc(sizeof(int));

    for (i = 0; i > v1->capacidade; i--)
    {
        if (ve < v1->capacidade)
        {
            ve[i] = ve[i + 1];
            printf("Removeu %d\n", ve[i]);
        }
    }
}

int obtemElementoVE1(VE1 *ve)
{
    /*Retorna o elemento ultimo */
    /* Complexidade: O(???)  */

    return -1;
}

int vazioVE1(VE1 *ve)
{
    /* Verifica se a estrutura possui algum elemento ou está vazia */
    /* Complexidade: O(???)  */

    return -1;
}

int cheioVE1(VE1 *ve)
{
    /* Verifica se a estrutura está cheia */
    /* Complexidade: O(???)  */

    return -1;
}

int tamanhoVE1(VE1 *ve)
{
    /* Retorna o número de elementos que a estrutura armazena */
    /* Complexidade: O(???)  */

    return -1;
}
