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
    Objeto *aux = f->inicio;
    Objeto *tmp;
    while (aux)
    {
        tmp = aux;
        aux = aux->proximo;
        free(aux);
    }

    free(f);
}

/* Insere um novo objeto a fila */
void enqueue(Fila *f, Objeto *o)
{
    if (f->inicio == NULL)
    {
        f->inicio = o;
        f->fim = o;
        f->n++;
        return;
    }
    f->fim->proximo = o;
    f->fim = f->fim->proximo;
    f->n++;
}

/*Remove (apaga) o primeiro elemento da fila */
void dequeue(Fila *f)
{
    if (!filaVazia(f))
    {
        Objeto *aux = f->inicio;
        f->inicio = f->inicio->proximo;
        free(aux);
        f->n--;
    }
}

/* Retorna o primeiro elemento da fila */
Objeto *front(Fila *f)
{
    return f->inicio;
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
    else
        return f->n;
}

/* Retorna uma cópia da fila passada como parâmetro */
Fila *copiaFila(Fila *f)
{
    Fila *Copia = criaFila();
    Objeto *aux = f->inicio;
    while (aux)
    {
        enqueue(Copia, copiaObjeto(aux));
        aux = aux->proximo;
    }
    return Copia;
}

/* Fução que imprime os elementos da fila 
 * Essa função pode ajudar a detectar problemas nos objetos da fila
 * Para imprimir um objeto, use a função imprimeObjeto.
 */
void imprimeFila(Fila *f, int tipo)
{
    Objeto *aux;
    for ((aux = f->inicio); (aux->proximo != NULL); (aux = aux->proximo))
    {
        imprimeObjeto(aux, tipo);
    }
    imprimeObjeto(aux, tipo);
}

/* Função de Alta Ordem que recebe uma fila e uma função (cb).
 * Para cada objeto da fila, aplique a função cb ao objeto.
 */
void converteElementosFila(Fila *f, void (*cb)(Objeto *))
{
    Objeto *aux = f->inicio;
    while (aux != NULL)
    {
        if (f != NULL)
        {
            cb(aux);
        }
        aux = aux->proximo;
    }
}