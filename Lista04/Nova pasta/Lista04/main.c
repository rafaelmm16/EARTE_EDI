#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Racional.h"

int main()
{
    Racional *x = inicializaRacional(5, 4);
    Racional *y = inicializaRacional(3, 2);
    Racional *z = NULL;

    imprimeRacional(x);
    imprimeRacional(y);
    //imprimeRacional(z);
    //houve um vazamento de memoria
    //já que a variavel não está inicializada

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
    //pois na função estamos dando um retorno
    //e aqui ela está indo para nenhum lugar
    //por isso precisa ser iniciada
    imprimeRacional(z);

    Racional *r = inicializaRacional(9, 6);
    if (comparaRacional(r, y))
    {
        printf("Sao iguais \n");
    }
    else
    {
        printf("Sao diferentes \n");
    }

    Racional *test;
    //Racional *test2 = NULL;
    test = somatorio();

    liberaRacional(x);
    liberaRacional(y);
    liberaRacional(z);
    liberaRacional(r);
    liberaRacional(test);
    //liberaRacional(test2);

    system("pause");
    return 0;
}