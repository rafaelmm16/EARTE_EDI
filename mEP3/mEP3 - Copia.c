#include <stdio.h>
#include <stdlib.h>


typedef struct no {
	int id;
    struct no *proximo;
} No;

typedef struct  lista {
    No *inicio;
} Lista;


Lista *criaLista() { //cria a lista
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

int vazia(Lista *lista){ //retorna a lista com inicio valendo NULL
    return (lista->inicio == NULL);
}

void inserir_fim(Lista *lista, int valor) {
    No *novo = malloc(sizeof(No)); //Alocando o novo No
    novo->id = valor;
    novo->proximo = NULL;
    
    if (vazia(lista)){ //chama a função vazia
        lista->inicio = novo;
    }else{
        No *auxiliar = lista->inicio;
        while(auxiliar->proximo != NULL){
            auxiliar = auxiliar->proximo;
        }
        auxiliar->proximo = novo;
    }
}

void imprimir (Lista *lista){ //imprime a lista
    No *new = lista->inicio;
    while(new != NULL){
        printf("%d -> ", new->id);
        new = new->proximo;
    }
    printf("NULL \n");
}

void liberar (Lista *lista){ //libera o espaço alocado
    No *new = lista->inicio;
    while(new != NULL) {
        No* n = new->proximo;
        free(new);
        new = n;
    }
    free(lista);
    lista = NULL;
}

Lista *juntaLista(Lista *l1, Lista *l2) { //junta a lista
    Lista *resultado = criaLista();
    if (l1 == NULL){
        return l2;
    } if (l2 == NULL){
        return l1;
    }
    
    No *primeiro = NULL;
    No *segundo = NULL;
    No *terceiro = NULL;

    primeiro = l1->inicio;
    segundo = l2->inicio;

    if (primeiro->id > segundo->id) {
        resultado->inicio = segundo; 
        terceiro = resultado->inicio; 
        segundo = segundo->proximo;
    } else{
        resultado->inicio = primeiro; 
        terceiro = resultado->inicio; 
        primeiro = primeiro->proximo;
    } 
    
    while(primeiro != NULL && segundo != NULL) {
        if (primeiro->id < segundo->id){
            terceiro->proximo = primeiro;
            primeiro = primeiro->proximo;
            terceiro = terceiro->proximo;
        }else{
            terceiro->proximo = segundo;
            segundo = segundo->proximo;
            terceiro = terceiro->proximo;
        }
    }

    if (primeiro == NULL){
        terceiro->proximo = segundo;
    }else{
        terceiro->proximo = primeiro;
    }

    return resultado;
}

int main (){

    Lista *primeiro_vagao = criaLista();
    Lista *segundo_vagao = criaLista();


 //teste - case 1

    inserir_fim(primeiro_vagao, 2);
    inserir_fim(primeiro_vagao, 3);
    inserir_fim(primeiro_vagao, 4);
    inserir_fim(primeiro_vagao, 6);
    inserir_fim(segundo_vagao, 1);
    inserir_fim(segundo_vagao, 5);
    inserir_fim(segundo_vagao, 7);
    inserir_fim(segundo_vagao, 8);
    inserir_fim(segundo_vagao, 9);

    Lista *novaLista = juntaLista(primeiro_vagao, segundo_vagao);
    free(primeiro_vagao);
    free(segundo_vagao);

    imprimir(novaLista);
    liberar (novaLista);

    return 0;
}

