#include <stdio.h>

//Retora a multiplicação de a * b(somatorio)
int M(int a, int b)
{
    if (b == 0)
        return 0;
    else if (b == 1)
        return a;
    else
        return a + M(a, b - 1);
}

//Divisão de inteiros
int DI(int a, int b)
{
    if (a < b)
        return 0;
    else
        return 1 + DI(a - b, b);
}

//resto da divisão
double RD(double a, double b)
{
    if (a < b)
        return a;
    else
        return RD(a - b, b);
}

int main()
{

    printf("%d\n", M(2, 3));
    printf("%d\n", M(4, 2));
    printf("%d\n", DI(2, 3));
    printf("%d\n", DI(3, 2));
    printf("%d\n", DI(4, 2));
    printf("%d\n", DI(10, 6));
    printf("%lf\n", RD(2, 3));
    printf("%lf\n", RD(3, 2));
    printf("%lf\n", RD(25.5, 10.5));

    /*Resultados:
    6
    8
    0
    1
    2
    1
    2.000000
    1.000000
    4.500000
    */

    return 0;
}