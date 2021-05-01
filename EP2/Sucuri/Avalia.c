#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Avalia.h"
#include "Categorias.h"
#include "Pilha.h"
#include "Util.h"

/* Recebe uma fila de objetos em notação pós-fixa,
 avalia e retorna o resultado da expressão */
Objeto *avalia(Fila *posFixa)
{
    Pilha *p = criaPilha();
    Objeto *auxFila = front(posFixa);
    Objeto *aux;
    Objeto *aux2;
    Objeto *tmp;
    Objeto *tmp2;

    while (auxFila != NULL)
    {
        int i = auxFila->categoria;
        switch (i)
        {

        case 11:
        case 12:
            empilha(p, copiaObjeto(auxFila));
            break;

        case 6:
            aux = copiaObjeto(topoPilha(p));
            desempilha(p);
            tmp = criaObjeto();

            if (aux->categoria == 12)
            {
                tmp->valor.vInt = aux->valor.vInt * (-1);
                tmp->categoria = 12;
            }
            else if (aux->categoria == 11)
            {
                tmp->valor.vFloat = aux->valor.vFloat * (-1);
                tmp->categoria = 11;
            }
            empilha(p, tmp);
            liberaObjeto(aux);
            break;

        case 5:
            aux = copiaObjeto(topoPilha(p));
            desempilha(p);
            aux2 = copiaObjeto(topoPilha(p));
            desempilha(p);
            tmp = criaObjeto();

            if (aux->categoria != 11 && aux2->categoria != 11)
            {
                tmp->valor.vInt = aux2->valor.vInt - aux->valor.vInt;
                tmp->categoria = 12;
            }
            else
            {
                if (aux->categoria == 12)
                    tmp->valor.vFloat = aux2->valor.vFloat - aux->valor.vInt;
                else if (aux2->categoria == 12)
                    tmp->valor.vFloat = aux2->valor.vInt - aux->valor.vFloat;
                else
                    tmp->valor.vFloat = aux2->valor.vFloat - aux->valor.vFloat;
                tmp->categoria = 11;
            }
            empilha(p, tmp);
            liberaObjeto(aux);
            liberaObjeto(aux2);
            break;

        case 4:
            aux = copiaObjeto(topoPilha(p));
            desempilha(p);
            aux2 = copiaObjeto(topoPilha(p));
            desempilha(p);
            tmp = criaObjeto();

            if (aux->categoria != 11 && aux2->categoria != 11)
            {
                tmp->valor.vInt = aux2->valor.vInt + aux->valor.vInt;
                tmp->categoria = 12;
            }
            else
            {
                if (aux->categoria == 12)
                    tmp->valor.vFloat = aux2->valor.vFloat + aux->valor.vInt;
                else if (aux2->categoria == 12)
                    tmp->valor.vFloat = aux2->valor.vInt + aux->valor.vFloat;
                else
                    tmp->valor.vFloat = aux2->valor.vFloat + aux->valor.vFloat;
                tmp->categoria = 11;
            }
            empilha(p, tmp);
            liberaObjeto(aux);
            liberaObjeto(aux2);
            break;

        case 3:
            aux = copiaObjeto(topoPilha(p));
            desempilha(p);
            aux2 = copiaObjeto(topoPilha(p));
            desempilha(p);
            tmp = criaObjeto();

            if (aux->categoria != 11 && aux2->categoria != 11)
            {
                tmp->valor.vInt = aux2->valor.vInt / aux->valor.vInt;
                tmp->categoria = 12;
            }
            else
            {
                if (aux->categoria == 12)
                    tmp->valor.vFloat = aux2->valor.vFloat / aux->valor.vInt;
                else if (aux2->categoria == 12)
                    tmp->valor.vFloat = aux2->valor.vInt / aux->valor.vFloat;
                else
                    tmp->valor.vFloat = aux2->valor.vFloat / aux->valor.vFloat;
                tmp->categoria = 11;
            }
            empilha(p, tmp);
            liberaObjeto(aux);
            liberaObjeto(aux2);
            break;

        case 2:
            aux = copiaObjeto(topoPilha(p));
            desempilha(p);
            aux2 = copiaObjeto(topoPilha(p));
            desempilha(p);
            tmp = criaObjeto();

            if (aux->categoria != 11 && aux2->categoria != 11)
            {
                tmp->valor.vInt = aux2->valor.vInt * aux->valor.vInt;
                tmp->categoria = 12;
            }
            else
            {
                if (aux->categoria == 12)
                    tmp->valor.vFloat = aux2->valor.vFloat * aux->valor.vInt;
                else if (aux2->categoria == 12)
                    tmp->valor.vFloat = aux2->valor.vInt * aux->valor.vFloat;
                else
                    tmp->valor.vFloat = aux2->valor.vFloat * aux->valor.vFloat;
                tmp->categoria = 11;
            }
            empilha(p, tmp);
            liberaObjeto(aux);
            liberaObjeto(aux2);
            break;

        case 1:
            aux = copiaObjeto(topoPilha(p));
            desempilha(p);
            aux2 = copiaObjeto(topoPilha(p));
            desempilha(p);
            tmp = criaObjeto();

            if (aux->categoria != 11 && aux2->categoria != 11)
            {
                tmp->valor.vInt = aux2->valor.vInt % aux->valor.vInt;
                tmp->categoria = 12;
            }
            else
            {
                if (aux->categoria == 12)
                    tmp->valor.vFloat = fmod(aux2->valor.vFloat, (float)aux->valor.vInt);
                else if (aux2->categoria == 12)
                    tmp->valor.vFloat = fmod((float)aux2->valor.vInt, aux->valor.vFloat);
                else
                    tmp->valor.vFloat = fmod(aux2->valor.vFloat, aux->valor.vFloat);
                tmp->categoria = 11;
            }

            empilha(p, tmp);
            liberaObjeto(aux);
            liberaObjeto(aux2);
            break;

        case 0:
            aux = copiaObjeto(topoPilha(p));
            desempilha(p);
            aux2 = copiaObjeto(topoPilha(p));
            desempilha(p);
            tmp = criaObjeto();

            if (aux->categoria != 11 && aux2->categoria != 11)
            {
                tmp->valor.vInt = pow(aux2->valor.vInt, aux->valor.vInt);
                tmp->categoria = 12;
            }
            else
            {
                if (aux->categoria == 12)
                    tmp->valor.vFloat = pow(aux2->valor.vFloat, aux->valor.vInt);
                else if (aux2->categoria == 12)
                    tmp->valor.vFloat = pow(aux2->valor.vInt, aux->valor.vFloat);
                else
                    tmp->valor.vFloat = pow(aux2->valor.vFloat, aux->valor.vFloat);
                tmp->categoria = 11;
            }
            empilha(p, tmp);
            liberaObjeto(aux);
            liberaObjeto(aux2);
            break;
        }
        auxFila = auxFila->proximo;
    }
    tmp2 = copiaObjeto(topoPilha(p));
    liberaPilha(p);

    return tmp2;
}
