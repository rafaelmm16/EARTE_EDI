#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvoreAVL.h"

NoAVL *criaNoAVL(int v)
{
    NoAVL *novo = malloc(sizeof(NoAVL));
    novo->dado = v;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->altura = 0;
    return novo;
}

void liberaAVL(NoAVL *r)
{
    if (r != NULL)
    {
        liberaAVL(r->esq);
        liberaAVL(r->dir);
        free(r);
    }
}

NoAVL *buscaAVL(NoAVL *r, int v)
{
    if (r == NULL || r->dado == v)
        return r;
    if (r->dado > v)
        return buscaAVL(r->esq, v);
    else
        return buscaAVL(r->dir, v);
}

void paddingAVL(char ch, int n)
{
    int i;
    for (i = 0; i < n; i++)
        putchar(ch);
}

void imprimeArvoreAVL(NoAVL *root, int level)
{
    if (root == NULL)
    {
        paddingAVL('\t', level);
        puts("~");
    }
    else
    {
        imprimeArvoreAVL(root->dir, level + 1);
        paddingAVL('\t', level);
        printf("%d\n", root->dado);
        imprimeArvoreAVL(root->esq, level + 1);
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int alturaAVL(NoAVL *r)
{
    if (r == NULL)
        return -1;
    return r->altura;
}

int fatorBalanceamento(NoAVL *r)
{
    return alturaAVL(r->esq) - alturaAVL(r->dir);
}

NoAVL *rotacaoDireita(NoAVL *A)
{
    //Complexidade: O(1)
    NoAVL *B = A->esq;

    //Realiza a rotação
    A->esq = B->dir;
    B->dir = A;

    //Atualiza a altura dos nós
    A->altura = max(alturaAVL(A->esq), alturaAVL(A->dir)) + 1;
    B->altura = max(alturaAVL(B->esq), alturaAVL(B->dir)) + 1;

    //Retorna a nova raiz
    return B;
}

NoAVL *rotacaoEsquerda(NoAVL *A)
{
    //Complexidade: O(??)
    NoAVL *B = A->dir;

    //Realiza a rotação
    A->dir = B->esq;
    B->esq = A;

    //Atualiza a altura dos nós
    A->altura = max(alturaAVL(A->esq), alturaAVL(A->dir)) + 1;
    B->altura = max(alturaAVL(B->esq), alturaAVL(B->dir)) + 1;

    //Retorna a nova raiz
    return B;
}

NoAVL *insere(NoAVL *r, NoAVL *novo)
{
    /*PASSO 1: Faz a inserção normal de uma ABB */
    if (r == NULL)
        return novo;
    if (r->dado > novo->dado)
        r->esq = insere(r->esq, novo);
    else
        r->dir = insere(r->dir, novo);

    //PASSO 2: Atualizar a altura do nó
    r->altura = max(alturaAVL(r->esq), alturaAVL(r->dir)) + 1;

    /*PASSO 3: Obter o fator de balanceamento do nó e verifica se é necessário o rebalanceamento */
    int fb = fatorBalanceamento(r);

    //Rotação RR
    if (fb > 1 && fatorBalanceamento(r->esq) >= 0)
        return rotacaoDireita(r);
    //Rotação LL
    if (fb < -1 && fatorBalanceamento(r->dir) <= 0)
        return rotacaoEsquerda(r);
    //Rotação LR
    if (fb > 1 && fatorBalanceamento(r->esq) < 0)
    {
        r->esq = rotacaoEsquerda(r->esq);
        return rotacaoDireita(r);
    }
    //Rotação RL
    if (fb < -1 && fatorBalanceamento(r->dir) > 0)
    {
        r->dir = rotacaoDireita(r->dir);
        return rotacaoEsquerda(r);
    }

    return r;
}