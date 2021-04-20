#include <stdio.h>
#include <stdlib.h>

#include "Categorias.h"
#include "Objeto.h"

Objeto *criaObjeto() {
    Objeto *obj = mallocSafe(sizeof(Objeto));
    obj->categoria  = INDEFINIDA;
    obj->valor.pStr = NULL;
    obj->proximo    = NULL;
    return obj;
}

/* Retorna uma cópia do objeto */
Objeto *copiaObjeto(Objeto *obj) {
    AVISO(Objeto.c: ainda não completei a função 'copiaObjeto');
    
    return NULL;
}

void liberaObjeto(Objeto *o) {
//    if (o->valor.pStr != NULL)
//        free(o->valor.pStr);
    free(o);
}

/*Imprime as informação do objeto de acordo com o 'tipo' (Util.h)*/
void imprimeObjeto(Objeto *obj, int tipo) {
    if (tipo == ITEM) {
        printf("  \"%s\" (%s)\n", obj->valor.pStr, getNomeCategoria(obj->categoria));
    }
    else if(tipo == VALOR) {
        if (obj->categoria >= 0 && obj->categoria <= 8) {
            printf("  prec=%d (%s)\n", obj->valor.vInt, getNomeCategoria(obj->categoria));
        }
        else if (obj->categoria >= 9 && obj->categoria <= 10) {
            printf("  %s (%s)\n", obj->valor.pStr, getNomeCategoria(obj->categoria));
        }
        else if (obj->categoria == FLOAT) {
            /*VALOR FLOAT*/
            printf("  %lf (valor float)\n", obj->valor.vFloat);
        }
        else if (obj->categoria == INT) {
            /*VALOR INT*/
            printf("  %d (valor int)\n", obj->valor.vInt);
        }
    }
    else if (tipo == POSFIXA) {
        AVISO(Objeto.c: ainda não completei a função 'imprimeObjeto');
        
    }
}

void imprimeValor(Objeto * obj) {
    if(obj->categoria == FLOAT)
        printf("%lf\n", obj->valor.vFloat);
    else if(obj->categoria == INT)
        printf("%d\n", obj->valor.vInt);
}