#include <stdio.h>

int potencia(int base, int exp)
{
    //int res = 1;

    if (exp == 1)
        return base;
    else
    {
        return base * potencia(base, exp - 1);
    }

    /*
    while (1)
    {
        if (exp == 0)
            break;
        else
        {
            res *= base;
            exp--;
        }
    }
    */

    /*
    for (int i = 0; i < exp - 1; i++)
    {
        res *= base;
    }

    return res;
    */
}

int main()
{

    int a = 2, b = 3;
    printf("Resultado: %d", potencia(a, b));

    return 0;
}