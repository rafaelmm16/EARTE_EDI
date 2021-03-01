#include <stdio.h>
#include <time.h> /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h> /* sqrt */

int frequency_of_primes(int n)
{
    int i, j;
    int freq = n - 1;
    for (i = 2; i <= n; ++i)
        for (j = sqrt(i); j > 1; --j)
            if (i % j == 0)
            {
                --freq;
                break;
            }
    return freq;
}

int fibo(int n)
{
    printf("Iniciando a funcao fibo(%d)\n", n);
    if (n < 2)
    {
        printf("Finalizando a funcao fibo(%d) com valor %d\n", n, n);
        return n;
    }

    int f = fibo(n - 1) + fibo(n - 2);
    printf("Finalizando a funcao fibo(%d) com valor %d\n", n, f);
    return f;
}

int fibo2(int n)
{
    int i = 0, aux, aux2 = 0, aux3 = 1;

    for (i = 0; i < n; i++)
    {
        aux = aux2 + aux3;
        aux2 = aux3;
        aux3 = aux;

        printf("Fibo(%d), %d\n", i + 2, aux);
    }

    return aux;
}

int main()
{

    clock_t t;
    int f;

    int num, fibonacci, fibonacci2;
    scanf("%d", &num);

    //fibonacci2 foi criada de forma iterativa
    fibonacci = fibo(num);
    //fibonacci2 = fibo2(num);
    printf("fibo(%d) = %d\n", num, fibonacci);
    //printf("fibo(%d) = %d\n", num, fibonacci2);

    t = clock();
    printf("Calculating...\n");
    f = frequency_of_primes(99999);
    printf("The number of primes lower than 100,000 is: %d\n", f);
    t = clock() - t;
    printf("It took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);

    return 0;
}