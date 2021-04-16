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
    //Nos auxiliares
    No *lista1_aux = NULL;
    No *lista2_aux = NULL;
    No *lista3_aux = NULL;

    lista1_aux = l1->inicio;
    lista2_aux = l2->inicio;

    //Enquanto a lista 1 não estiver no final (NULL),
    //ele aponta o valor no próximo da l1,
    //e depois ele vai apontando l1 no início de l2
    //fazendo assim a concatenação das Listas

    if (lista1_aux->id > lista2_aux->id)
    {
        resultado->inicio = lista2_aux;
        lista3_aux = resultado->inicio;
        lista2_aux = lista2_aux->proximo;
    }
    else
    {
        resultado->inicio = lista1_aux;
        lista3_aux = resultado->inicio;
        lista1_aux = lista1_aux->proximo;
    }

    while (lista1_aux != NULL && lista2_aux != NULL)
    {
        if (lista1_aux->id < lista2_aux->id)
        {
            lista3_aux->proximo = lista1_aux;
            lista1_aux = lista1_aux->proximo;
            lista3_aux = lista3_aux->proximo;
        }
        else
        {
            lista3_aux->proximo = lista2_aux;
            lista2_aux = lista2_aux->proximo;
            lista3_aux = lista3_aux->proximo;
        }
    }

    if (lista1_aux == NULL)
        lista3_aux->proximo = lista2_aux;
    else
        lista3_aux->proximo = lista1_aux;

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