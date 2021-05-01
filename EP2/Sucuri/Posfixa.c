#include <stdio.h>
#include <stdlib.h>

#include "Posfixa.h"
#include "Pilha.h"

/* A função recebe uma fila de objetos em notação infixa e converte (retorna) 
 * a correspondente em notação pós-fixa.
 * Para evitar problemas de vazamento de memória e/ou falha de segmentação, faça 
 * cópia dos objetos. 
 * Lembre-se que a função 'desempilha' (Pilha.h) e 'dequeue' (Fila.h)
 * fazem a desalocação dos objetos(liberaObjeto)
 */
Fila *infixaParaPosfixa(Fila *infixa)
{
    Pilha *p = criaPilha();
    Fila *f = criaFila();
    Objeto *Copia = NULL;
    Objeto *Top = front(infixa);
    Objeto *Factor = NULL;

    while (Top)
    {
        if (Top->categoria == 9 || Top->categoria == 10 || Top->categoria == 11 || Top->categoria == 12)
            enqueue(f, copiaObjeto(Top));
        else if (Top->categoria == 7)
            empilha(p, copiaObjeto(Top));
        else if (Top->categoria == 8)
        {
            Copia = topoPilha(p);
            while (topoPilha(p) && topoPilha(p)->categoria != 7)
            {
                enqueue(f, copiaObjeto(topoPilha(p)));
                desempilha(p);
            }
            if (topoPilha(p))
                desempilha(p);
        }
        else
        {
            Factor = copiaObjeto(Top);
            while (topoPilha(p) != NULL && topoPilha(p)->valor.vInt >= Top->valor.vInt)
            {
                if ((topoPilha(p)->categoria == 0 && Top->categoria == 6) || (topoPilha(p)->categoria == 6 && Top->categoria == 0))
                {
                    break;
                }
                else
                {
                    enqueue(f, copiaObjeto(topoPilha(p)));
                    desempilha(p);
                }
            }
            empilha(p, Factor);
        }
        Top = Top->proximo;
    }
    while (topoPilha(p))
    {
        enqueue(f, copiaObjeto(topoPilha(p)));
        desempilha(p);
    }
    liberaPilha(p);
    return f;
}

void imprimePosFixa(Fila *posfixa)
{
    Fila *f = copiaFila(posfixa);
    while (!filaVazia(f))
    {
        Objeto *obj = front(f);
        imprimeObjeto(obj, POSFIXA);
        dequeue(f);
    }
    printf("\n");
    liberaFila(f);
}