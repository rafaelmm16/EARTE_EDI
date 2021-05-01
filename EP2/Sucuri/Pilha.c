#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

typedef struct pilha
{
    Objeto *inicio;
    int n;
} Pilha;

Pilha *criaPilha()
{
    Pilha *p = mallocSafe(sizeof(Pilha));
    p->inicio = NULL;
    p->n = 0;
    return p;
}

/* Faz a desalocação da pilha */
void liberaPilha(Pilha *p)
{
    Objeto *aux = p->inicio;
    Objeto *aux2 = NULL;
    while (aux)
    {
        aux2 = aux;
        aux = aux->proximo;
        free(aux2);
    }
    free(p);
}

/* Insere um novo objeto a pilha */
void empilha(Pilha *p, Objeto *no)
{
    no->proximo = p->inicio;
    p->inicio = no;
    p->n++;
}

/* Remove (apaga) o último elemento da pilha */
void desempilha(Pilha *p)
{
    if (!p)
    {
        printf("ERRO: Pilha Vazia!");
        return;
    }
    else
    {
        Objeto *aux = p->inicio;
        p->inicio = p->inicio->proximo;
        free(aux);
        p->n--;
    }
}

/* Retorna o objeto do topo da pilha */
Objeto *topoPilha(Pilha *p)
{
    if (!p)
    {
        printf("ERRO: Pilha Vazia!");
        return NULL;
    }
    return p->inicio;
}

/* Verifica se a pilha está vazia */
bool pilhaVazia(Pilha *p)
{
    return (p == NULL || p->n == 0);
}

/* Retorna o número de elementos na pilha */
int tamanhoPilha(Pilha *p)
{
    if (pilhaVazia(p))
        return 0;
    else
        return p->n;
}

/* Fução que imprime os elementos da pilha 
 * Essa função pode ajudar a detectar problemas nos objetos da pilha
 * Para imprimir um objeto, use a função imprimeObjeto.
 */
void imprimePilha(Pilha *pilha, int tipo)
{
    Objeto *aux = NULL;
    for ((aux = pilha->inicio); (aux->proximo != NULL); (aux = aux->proximo))
    {
        imprimeObjeto(aux, tipo);
    }
    imprimeObjeto(aux, tipo);
}