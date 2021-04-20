#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

struct fila
{
    Objeto *inicio;
    Objeto *fim;
    int n;
};

Fila *criaFila()
{
    Fila *f = mallocSafe(sizeof(Fila));
    f->inicio = f->fim = NULL;
    f->n = 0;
    return f;
}

/* Faz a desalocação da fila */
void liberaFila(Fila *f)
{
    //AVISO(Fila.c: ainda não completei a função 'liberaFila');
    Fila *aux = f->inicio;
    while (aux)
    {
        Fila *t;
        t = aux->inicio;
        free(aux);
        aux = t;
    }
    free(f);
    f = NULL;
}

/* Insere um novo objeto a fila */
void enqueue(Fila *f, Objeto *o)
{
    //AVISO(Fila.c: ainda não completei a função 'enqueue');

    Fila *novo = malloc(sizeof(Fila));
    novo->n = o->categoria;
    novo->inicio = NULL;
    if (filaVazia(f))
        f->inicio = novo->inicio;
    else
        f->fim->proximo = novo->fim;

    f->fim = novo->fim;
    f->n++;
}

/*Remove (apaga) o primeiro elemento da fila */
void dequeue(Fila *f)
{
    //AVISO(Fila.c: ainda não completei a função 'dequeue');

    if (!filaVazia(f))
    {
        Fila *tmp;
        tmp = f->inicio;
        f->inicio = f->inicio->proximo;
        f->n--;
        free(tmp);
    }
    else
        printf("ERRO: Fila vazia!\n");
}

/* Retorna o primeiro elemento da fila */
Objeto *front(Fila *f)
{
    //AVISO(Fila.c
    //: ainda não completei a função 'front');

    if (filaVazia(f))
    {
        printf("ERRO: Fila vazia!");
        return NULL;
    }
    else
        return f->inicio;
    //return NULL;
}

/* Verifica se a fila está vazia */
bool filaVazia(Fila *f)
{
    return (f == NULL || f->n == 0);
}

/* Retorna o número de elementos na fila */
int tamanhoFila(Fila *f)
{
    if (filaVazia(f))
        return 0;
    return f->n;
}

/* Retorna uma cópia da fila passada como parâmetro */
Fila *copiaFila(Fila *f)
{
    //AVISO(Fila.c
    //: ainda não completei a função 'copiaFila');

    if (!f)
    {
        return NULL;
    }

    Fila *copia = NULL;
    copia = mallocSafe(sizeof(Fila));

    copia->inicio = f->inicio;
    copia->fim = f->fim;
    copia->n = f->n;

    return copia;
    //return NULL;
}

/* Fução que imprime os elementos da fila 
 * Essa função pode ajudar a detectar problemas nos objetos da fila
 * Para imprimir um objeto, use a função imprimeObjeto.
 */
void imprimeFila(Fila *f, int tipo)
{
    Fila *atual;
    atual = f->inicio;
    while (atual != NULL)
    {
        if (compara(atual->n))
            printf("%d -> ", atual->n);
        atual->inicio = atual->inicio;
    }
    printf("NULL\n");
}

/* Função de Alta Ordem que recebe uma fila e uma função (cb).
 * Para cada objeto da fila, aplique a função cb ao objeto.
 */
void converteElementosFila(Fila *f, void (*cb)(Objeto *))
{
    AVISO(Fila.c
          : ainda não completei a função 'converteElementosFila');
}