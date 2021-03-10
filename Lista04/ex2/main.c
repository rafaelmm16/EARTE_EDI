#include <stdio.h>
#include <stdlib.h>

#include "Racional.h"

int main()
{
    Racional *x = inicializaRacional(5, 4);
    Racional *y = inicializaRacional(3, 2);
    Racional *z = NULL;

    imprimeRacional(x);
    imprimeRacional(y);
    //imprimeRacional(z);

    setDen(x, 13);
    imprimeRacional(x);
    //x->den = 0;
    imprimeRacional(x);

    z = multiplicaRR(x, y);
    imprimeRacional(z);
    z = multiplicaRI(z, 3);
    imprimeRacional(z);
    printf("\n");
    //z->den = 13;
    imprimeRacional(z);
    liberaRacional(z);

    z = somaRR(x, y);
    imprimeRacional(z);
    z = somaRI(z, 3); //Aqui temos um vazamento de mamória. Por quê?
    imprimeRacional(z);

    Racional *r = inicializaRacional(9, 6);
    if (comparaRacional(r, y))
    {
        printf("São iguais \n");
    }
    else
    {
        printf("São diferentes \n");
    }

    liberaRacional(x);
    liberaRacional(y);
    liberaRacional(z);
    liberaRacional(r);

    system("pause");
    return 0;
}