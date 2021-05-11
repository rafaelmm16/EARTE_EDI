#ifndef EP3_arvore_H
#define EP3_arvore_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    int dado;
    struct no *esq;
    struct no *dir;
} No;

No *criaNo(int v);

void imprime(No *r);

void padding(char ch, int n);

void imprimeArvore(No *root, int nivel);

void libera(No *r);

No *busca(No *r, int v);

int altura(No *r);

int numeroNo(No *raiz);

No *insereNo(No *raiz, No *novo);

No *removeNo(No *raiz, int chave);

#endif