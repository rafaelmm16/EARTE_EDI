#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int id;
    struct no *proximo;
} No;

typedef struct lista
{
    No *inicio;
} Lista;

Lista *criaLista()
{
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

int listaVazia(Lista *lista)
{
    return (lista->inicio == NULL);
}

void insereFimLista(Lista *lista, int elemento)
{
    No *novo = malloc(sizeof(No));
    novo->id = elemento;
    novo->proximo = NULL;
    if (listaVazia(lista))
    {
        lista->inicio = novo;
    }
    else
    {
        No *aux = lista->inicio;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void imprimeLista(Lista *lista)
{
    No *atual = lista->inicio;
    while (atual != NULL)
    {
        printf("%d -> ", atual->id);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void liberaLista(Lista *lista)
{
    No *atual = lista->inicio;
    while (atual != NULL)
    {
        No *t = atual->proximo;
        free(atual);
        atual = t;
    }
    free(lista);
    lista = NULL;
}

Lista *juntaLista(Lista *l1, Lista *l2)
{
    Lista *resultado = criaLista();
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    No *aux1 = NULL;
    No *aux2 = NULL;
    No *aux3 = NULL;

    aux1 = l1->inicio;
    aux2 = l2->inicio;

    if (aux1->id > aux2->id)
    {
        resultado->inicio = aux2;
        aux3 = resultado->inicio;
        aux2 = aux2->proximo;
    }
    else
    {
        resultado->inicio = aux1;
        aux3 = resultado->inicio;
        aux1 = aux1->proximo;
    }

    while (aux1 != NULL && aux2 != NULL)
    {
        if (aux1->id < aux2->id)
        {
            aux3->proximo = aux1;
            aux1 = aux1->proximo;
            aux3 = aux3->proximo;
        }
        else
        {
            aux3->proximo = aux2;
            aux2 = aux2->proximo;
            aux3 = aux3->proximo;
        }
    }
    if (aux1 == NULL)
        aux3->proximo = aux2;
    else
        aux3->proximo = aux1;

    return resultado;
}

int main()
{
    Lista *vagao1 = criaLista();
    Lista *vagao2 = criaLista();

    insereFimLista(vagao1, 2);
    insereFimLista(vagao1, 3);
    insereFimLista(vagao1, 4);
    insereFimLista(vagao1, 6);

    insereFimLista(vagao2, 1);
    insereFimLista(vagao2, 5);
    insereFimLista(vagao2, 7);
    insereFimLista(vagao2, 8);
    insereFimLista(vagao2, 9);

    imprimeLista(vagao1);
    imprimeLista(vagao2);
    imprimeLista(juntaLista(vagao1, vagao2));

    liberaLista(juntaLista(vagao1, vagao2));
    liberaLista(vagao1);
    liberaLista(vagao2);

    return 0;
}