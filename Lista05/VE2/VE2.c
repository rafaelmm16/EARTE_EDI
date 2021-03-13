#include <stdio.h>
#include <stdlib.h>

#include "VE2.h"

struct ve2 {
    int capacidade; //Tamanho do array F
    int ini;        //Posicao do "primeiro" elemento
    int fim;        //Posição livre onde um elemento deve ser inserido
    int n;          //Número de elementos na estrutura
    int *F;         //Array para armazenar os elementos
};

VE2 *criaVE2(int capacidade) {
    /*Verifique se o valor em capacidade é válido */
    /*Se for, inicialize n, ini e fim com 0 (indicando que a estrutura está vazia) */
    /*Aloque o array 'F' e retorne o ponteiro da estrutura */


    return NULL;
}

void liberaVE2(VE2 *ve) {
    /* Faz a desalocação de memória */
}

void adicionaVE2(VE2 *ve, int v) {
    /* Adiciona um elemento no fim do vetor */
    /* Lembre-se de verificar se há espaço para adicionar o elemento */
    /* Complexidade: O(???)  */              


}

void removeVE2(VE2 *ve) {
    /* Retira o ultimo elemento*/
    /* Complexidade: O(???)  */

    
}

int obtemElementoVE2(VE2 *ve){
    /*Retorna o elemento ultimo */
    /* Complexidade: O(???)  */

    return -1;
}

int vazioVE2(VE2 *ve) {
    /* Verifica se a estrutura está vazia */
    /* Complexidade: O(???)  */

    return -1;
}

int cheioVE2(VE2 *ve) {
    /* Verifica se a estrutura está cheia */
    /* Complexidade: O(???)  */

    return -1;
}

int tamanhoVE2(VE2 *ve) {
    /* Retorna o número de elementos que a estrutura armazena */
    /* Complexidade: O(???)  */

    return -1;
}

/*Nessa estrutura, é utilizado o campo 'ini' para indicar  a posição do primeiro elemento, que não necessariamente está na posição 0. */
/* O que mudaria se optarmos por não usar esse campo e sempre manter o primeiro elemento na posição 0? */
/* A complexidade para inserir e remover um elemento seriam as mesmas? */
/* Escreva abaixo, em forma de comentário, a sua resposta */
