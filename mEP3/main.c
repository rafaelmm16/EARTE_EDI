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
int vazia(Lista *lista)
{ //retorna a lista com inicio valendo NULL
    return (lista->inicio == NULL);
}
void inserir_fim(Lista *lista, int valor)
{
    No *novo = malloc(sizeof(No)); //Alocando o novo No
    novo->id = valor;
    novo->proximo = NULL;

    if (vazia(lista))
    { //chama a função vazia
        lista->inicio = novo;
    }
    else
    {
        No *auxiliar = lista->inicio;
        while (auxiliar->proximo != NULL)
        {
            auxiliar = auxiliar->proximo;
        }
        auxiliar->proximo = novo;
    }
}

void imprimir(Lista *lista)
{ //imprime a lista
    No *new = lista->inicio;
    while (new != NULL)
    {
        printf("%d -> ", new->id);
        new = new->proximo;
    }
    printf("NULL \n");
}

void liberar(Lista *lista)
{ //libera o espaço alocado
    No *new = lista->inicio;
    while (new != NULL)
    {
        No *n = new->proximo;
        free(new);
        new = n;
    }
    free(lista);
    lista = NULL;
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

int main()
{
    Lista *lista1 = criaLista();
    Lista *lista2 = criaLista();

    inserir_fim(lista1, 2);
    inserir_fim(lista1, 3);
    inserir_fim(lista1, 4);
    inserir_fim(lista1, 6);
    inserir_fim(lista2, 1);
    inserir_fim(lista2, 5);
    inserir_fim(lista2, 7);
    inserir_fim(lista2, 8);
    inserir_fim(lista2, 9);

    Lista *novaLista = juntaLista(lista1, lista2);
    free(lista1);
    free(lista2);

    imprimir(novaLista);
    liberar(novaLista);

    return 0;
}