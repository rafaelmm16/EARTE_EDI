#ifndef EP3_arvoreAVL_H
#define EP3_arvoreAVL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noAVL
{
    int dado;
    struct noAVL *esq;
    struct noAVL *dir;
    int altura;
} NoAVL;

NoAVL *criaNoAVL(int v);

void liberaAVL(NoAVL *r);

NoAVL *buscaAVL(NoAVL *r, int v);

void paddingAVL(char ch, int n);

void imprimeArvoreAVL(NoAVL *root, int level);

int max(int a, int b);

int alturaAVL(NoAVL *r);

int fatorBalanceamento(NoAVL *r);

NoAVL *rotacaoDireita(NoAVL *A);

NoAVL *rotacaoEsquerda(NoAVL *A);

NoAVL *insere(NoAVL *r, NoAVL *novo);

#endif