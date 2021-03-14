#include <stdio.h>
#include <stdlib.h>

#include "VE2.h"

struct ve2
{
    int capacidade; //Tamanho do array F
    int ini;        //Posicao do "primeiro" elemento
    int fim;        //Posição livre onde um elemento deve ser inserido
    int n;          //Número de elementos na estrutura
    int *F;         //Array para armazenar os elementos
};

VE2 *criaVE2(int capacidade)
{
    /*Verifique se o valor em capacidade é válido */
    /*Se for, inicialize n, ini e fim com 0 (indicando que a estrutura está vazia) */
    /*Aloque o array 'F' e retorne o ponteiro da estrutura */
    if (capacidade < 1)
    {
        return NULL;
    }
    VE2 *ve = malloc(sizeof(VE2));

    ve->capacidade = capacidade;

    ve->n = 0;
    ve->ini = 0;
    ve->fim = 0;

    ve->F = malloc(capacidade * sizeof(int));

    if (ve->F == NULL)
    {
        free(ve);
        printf("Sem memoria\n");
        exit(1);
    }
    else
    {
        for (int i = 0; i < capacidade; i++)
        {
            ve->F[i] = -1;
        }
    }

    return ve;
}

void liberaVE2(VE2 *ve)
{
    /* Faz a desalocação de memória */
    if (ve != NULL)
    {
        ve = NULL;
        free(ve);
    }
}

void adicionaVE2(VE2 *ve, int v)
{
    /* Adiciona um elemento no fim do vetor */
    /* Lembre-se de verificar se há espaço para adicionar o elemento */
    /* Complexidade: O(n)  */

    if (ve->n == ve->capacidade)
    {
        printf("Sem memoria\n");
        return;
    }

    ve->F[ve->fim % ve->capacidade] = v;
    ve->fim++;
    ve->n++;
}

void removeVE2(VE2 *ve)
{
    /* Retira o ultimo elemento*/
    /* Complexidade: O(n)  */
    ve->ini = (ve->ini + 1) % ve->capacidade;
    ve->n--;
}

int obtemElementoVE2(VE2 *ve)
{
    /*Retorna o elemento ultimo */
    /* Complexidade: O(1)  */

    return ve->F[ve->ini];
}

int vazioVE2(VE2 *ve)
{
    /* Verifica se a estrutura está vazia */
    /* Complexidade: O(n)  */

    if (ve->n == 0)
    {
        return 1;
    }

    return 0;
}

int cheioVE2(VE2 *ve)
{
    /* Verifica se a estrutura está cheia */
    /* Complexidade: O(n)  */

    if (ve->capacidade == ve->n)
    {
        return 1;
    }
    return 0;
}

int tamanhoVE2(VE2 *ve)
{
    /* Retorna o número de elementos que a estrutura armazena */
    /* Complexidade: O(1)  */
    return ve->n;
}

/*Nessa estrutura, é utilizado o campo 'ini' para indicar  a posição do primeiro elemento, que não necessariamente está na posição 0. */
/* O que mudaria se optarmos por não usar esse campo e sempre manter o primeiro elemento na posição 0? */
/* A complexidade para inserir e remover um elemento seriam as mesmas? */
/* Escreva abaixo, em forma de comentário, a sua resposta */
/*Ficarai complicado percorrer sendo que não teriamos uma noção exata de onde o elemento esta*/
/*Não, provavelmente iria ser um log O(n²)*/