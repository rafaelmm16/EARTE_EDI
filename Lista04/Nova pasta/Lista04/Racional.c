#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Racional.h"

struct racional
{
    long num;
    long den;
};

Racional *inicializaRacional(long n, long d)
{
    if (d == 0)
    {
        printf("O denominador deve ser diferente de 0!\n");
        return NULL;
    }
    Racional *r = (Racional *)malloc(sizeof(Racional));
    if (r == NULL)
    {
        fprintf(stderr, "Sem memória!\n");
        exit(1);
    }

    r->num = n;
    r->den = d;

    return r;
}

void liberaRacional(Racional *r)
{
    if (r != NULL)
    { //Evita a tentativa de desalocação de um ponteiro não alocado
        free(r);
        r = NULL; //Evita ponteiros soltos
    }
}

void setNum(Racional *r, long n)
{
    r->num = n;
}

void setDen(Racional *r, long d)
{
    if (d == 0)
    {
        printf("O denominador deve ser diferente de 0!\n");
        return;
    }
    r->den = d;
}

long getNum(Racional *r)
{
    return r->num;
}

long getDen(Racional *r)
{
    return r->den;
}

void imprimeRacional(Racional *r)
{

    if (r == NULL)
    {
        printf("Sem memoria 01\n");
        exit(1);
    }
    else
        printf("%ld/%ld\n", r->num, r->den);
}

Racional *multiplicaRR(Racional *r1, Racional *r2)
{
    /* Retorna o resultado de r1*r2 */
    //AVISO(Ainda não implementei a função 'multiplicaRR');
    //Racional *res;
    Racional *res = (Racional *)malloc(sizeof(Racional));

    if (res == NULL)
    {
        printf("Sem memoria 02\n");
        exit(1);
    }
    else
    {
        res->num = r1->num * r2->num;
        res->den = r1->den * r2->den;

        return res;
    }
}

Racional *multiplicaRI(Racional *r, long a)
{
    /* Retorna o resultado de r*a */
    //AVISO(Ainda não implementei a função 'multiplicaRI');

    r->num = r->num * a;
    r->den = r->den;

    return r;
    //return NULL;
}

bool comparaRacional(Racional *r1, Racional *r2)
{
    /* Retorna true se r1 == r2 e false, caso contrário */
    //AVISO(Ainda não implementei a função 'comparaRacional');

    if (r1 == r2)
    {
        return true;
    }
    else
        return false;
}

Racional *somaRR(Racional *r1, Racional *r2)
{
    /* Retorna o resultado de r1+r2 */
    //AVISO(Ainda não implementei a função 'somaRR');
    Racional *res = (Racional *)malloc(sizeof(Racional));

    if (res == NULL)
    {
        printf("Sem memoria 02\n");
        exit(1);
    }
    else
    {
        res->num = (r1->num * r2->den) + (r2->num * r1->den);
        res->den = (r1->den * r2->den);

        return res;
    }
}

Racional *somaRI(Racional *r, long a)
{
    /* Retorna o resultado da soma de r + a */
    //AVISO(Ainda não implementei a função 'somaRR');

    r->num = (r->den * a) + (r->num * a);
    r->den = r->den;

    return r;
}
//não finalizei a função da numero 3
Racional *somatorio()
{
    int n, i = 0;
    Racional *soma = (Racional *)malloc(sizeof(Racional));

    if (soma == NULL)
    {
        printf("Sem memoria\n");
        exit(1);
    }
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        soma->num = 1;
        soma->den += soma->num / pow(soma->den, i);

        printf("%d\n", soma);
    }

    return soma;
}