#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

Lista *criaLista()
{
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

Lista *juntaLista(Lista *l1, Lista *l2)
{
    Lista *resultado = criaLista();
    /* Complete o código da função */
    /* Não faça nenhuma alocação e nem crie outras funções */

    //verificação das Listas se forem nulas
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