#include <stdio.h>
#include <stdlib.h>

#include "Categorias.h"
#include "Objeto.h"

Objeto *criaObjeto()
{
    Objeto *obj = mallocSafe(sizeof(Objeto));
    obj->categoria = INDEFINIDA;
    obj->valor.pStr = NULL;
    obj->proximo = NULL;
    return obj;
}

/* Retorna uma cópia do objeto */
Objeto *copiaObjeto(Objeto *obj)
{
    if (obj == NULL)
    {
        return NULL;
    }

    Objeto *copia = criaObjeto();

    copia->categoria = obj->categoria;
    copia->proximo = obj->proximo;

    if (obj->categoria == INT)
    {
        copia->valor.vInt = obj->valor.vInt;
    }
    else if (obj->categoria == FLOAT)
    {
        copia->valor.vFloat = obj->valor.vFloat;
    }
    else
    {
        copia->valor.pStr = obj->valor.pStr;
    }

    return copia;
}

void liberaObjeto(Objeto *o)
{
    free(o);
}

/*Imprime as informação do objeto de acordo com o 'tipo' (Util.h)*/
void imprimeObjeto(Objeto *obj, int tipo)
{
    if (tipo == ITEM)
    {
        printf("  \"%s\" (%s)\n", obj->valor.pStr, getNomeCategoria(obj->categoria));
    }
    else if (tipo == VALOR)
    {
        if (obj->categoria >= 0 && obj->categoria <= 8)
        {
            printf("  prec=%d (%s)\n", obj->valor.vInt, getNomeCategoria(obj->categoria));
        }
        else if (obj->categoria >= 9 && obj->categoria <= 10)
        {
            printf("  %s (%s)\n", obj->valor.pStr, getNomeCategoria(obj->categoria));
        }
        else if (obj->categoria == FLOAT)
        {
            /*VALOR FLOAT*/
            printf("  %lf (valor float)\n", obj->valor.vFloat);
        }
        else if (obj->categoria == INT)
        {
            /*VALOR INT*/
            printf("  %d (valor int)\n", obj->valor.vInt);
        }
    }
    else if (tipo == POSFIXA)
    {
        if (obj->categoria >= 0 && obj->categoria <= 6)
        {
            int elemento = obj->categoria;
            switch (elemento)
            {
            case 0:
                printf("^ ");
                break;
            case 1:
                printf("%% ");
                break;
            case 2:
                printf("* ");
                break;
            case 3:
                printf("/ ");
                break;
            case 4:
                printf("+ ");
                break;
            case 5:
                printf("- ");
                break;
            case 6:
                printf("_ ");
                break;
            }
        }
        else if (obj->categoria == FLOAT)
        {
            printf("%lf ", obj->valor.vFloat);
        }
        else if (obj->categoria == INT)
        {
            printf("%d ", obj->valor.vInt);
        }
    }
}

void imprimeValor(Objeto *obj)
{
    if (obj->categoria == FLOAT)
        printf("%lf\n", obj->valor.vFloat);
    else if (obj->categoria == INT)
        printf("%d\n", obj->valor.vInt);
}