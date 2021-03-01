#include <stdio.h>

int fatorial(int n){
    printf("Iniciando a funcao fatorial(%d)\n", n);
    if (n <= 1){
        printf("Finalizando a funcao fatorial(%d) com valor 1\n", n);
        return 1;
    }
    int fat = fatorial(n - 1);
    printf("Finalizando a funcao fatorial(%d) com valor %d\n", n, n*fat);
    return n*fat;
}

int main() {
    int n, fat;
    scanf("%d", &n);
    fat = fatorial(n);
    printf("%d! = %d\n", n, fat);

    return 0;
}