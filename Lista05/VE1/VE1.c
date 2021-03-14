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
    if (capacidade < 1)
    {
        return NULL;
    }

    struct ve1 *VE1;

    VE1 = malloc(sizeof(VE1));
    if (VE1 == NULL)
    {
        printf("Sem memoria\n");
        exit(1);
    }

    VE1->capacidade = capacidade;

    VE1->n = -1;

    VE1->P = malloc(capacidade * sizeof(int));

    if (VE1->P == NULL)
    {
        free(VE1);
        printf("Sem memoria\n");
        exit(1);
    }
    else
    {
        for (int i = 0; i < capacidade; i++)
        {
            VE1->P[i] = -1;
        }
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
    /* Complexidade: O(n)  */

    if (ve == NULL || ve->P == NULL)
    {
        printf("Sem memoria\n");
        return;
    }
    if (ve->n < ve->capacidade - 1)
    {
        ve->n++;
        ve->P[ve->n] = v;
    }
    else
    {
        printf("Sem espaco\n");
    }
}

void removeVE1(VE1 *ve)
{
    /* Retira o ultimo elemento*/
    /* Complexidade: O(n)  */

    if (ve->n < 0)
    {
        return;
    }
    ve->P[ve->n] = -1;
    ve->n--;
}

int obtemElementoVE1(VE1 *ve)
{
    /*Retorna o elemento ultimo */
    /* Complexidade: O(1)  */

    return ve->P[ve->n];
}

int vazioVE1(VE1 *ve)
{
    /* Verifica se a estrutura possui algum elemento ou está vazia */
    /* Complexidade: O(1)  */

    if (ve->P[0] >= 0)
    {
        return 0;
    }

    return 1;
}

int cheioVE1(VE1 *ve)
{
    /* Verifica se a estrutura está cheia */
    /* Complexidade: O(n)  */

    if (ve->capacidade == ve->n + 1)
    {
        return 1;
    }
    return 0;
}

int tamanhoVE1(VE1 *ve)
{
    /* Retorna o número de elementos que a estrutura armazena */
    /* Complexidade: O(n)  */

    int i = 0;
    int soma = 0;

    for (i = 0; i < ve->capacidade; i++)
    {
        if (ve->P[i] >= 0)
        {
            soma++;
        }
    }
    return soma;
}
