#include <stdio.h>
#include <stdlib.h>

#define AVISO(msg) fprintf(stdout, "AVISO: %s\n", #msg)
#define ERRO(msg) fprintf(stderr, "ERRO: %s\n", #msg)

typedef enum
{
    false,
    true
} bool;

typedef struct racional
{
    long num;
    long den;
} Racional;

Racional *inicializaRacional(long n, long d)
{
    if (d == 0)
    {
        printf("O denominador deve ser diferente de 0!\n");
        return NULL;
    }
    Racional *r = malloc(sizeof(Racional));
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
        printf("Sem memoria \n");
        exit(1);
    }
    else
        printf("%ld/%ld\n", r->num, r->den);
}

Racional *multiplicaRR(Racional *r1, Racional *r2)
{
    /* Retorna o resultado de r1*r2 */
    //AVISO(Ainda não implementei a função 'multiplicaRR');
    long res;

    res = r1->num * r2->den;

    return res;
}

Racional *multiplicaRI(Racional *r, long a)
{
    /* Retorna o resultado de r*a */
    //AVISO(Ainda não implementei a função 'multiplicaRI');

    long res;
    if (res == NULL)
    {
        printf("Sem memoria \n");
        exit(1);
    }
    else
    {
        res = r->den * a;

        return res;
    }

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

    long res = 0;

    res = r1 + r2->den;

    return res;
}

Racional *somaRI(Racional *r, long a)
{
    /* Retorna o resultado da soma de r + a */
    //AVISO(Ainda não implementei a função 'somaRR');

    long res = 0;

    res = r + a;

    return res;
}

int main()
{
    Racional *x = inicializaRacional(5, 4);
    Racional *y = inicializaRacional(3, 2);
    Racional *z = inicializaRacional(3, 2);
    imprimeRacional(x);
    imprimeRacional(y);
    imprimeRacional(z);

    setDen(x, 13);
    imprimeRacional(x);
    x->den = 0;
    imprimeRacional(x);

    z = multiplicaRR(x, y);
    imprimeRacional(z);
    multiplicaRI(z, 3);
    imprimeRacional(z);
    printf("\n");
    z->den = 13;
    imprimeRacional(z);
    liberaRacional(z);

    z = somaRR(x, y);
    imprimeRacional(z);
    z = somaRI(z, 3); //Aqui temos um vazamento de mamória. Por quê?
    imprimeRacional(z);
    /*
    Racional *r = inicializaRacional (9, 6);
    if ( comparaRacional (r, y))
        printf ("São iguais \n");
    else
        printf ("São diferentes \n");
*/
    liberaRacional(x);
    liberaRacional(y);
    liberaRacional(z);
    return 0;
}