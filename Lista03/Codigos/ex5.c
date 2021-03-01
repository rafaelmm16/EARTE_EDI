//A)copia uma string de tamanho 257
//B)Imprime a primeira posição char
//Obs, a variavel s[0] tem q ser trocada,
//ficando msg[0], se não ira dar erro

#include <stdio.h>

void imprime(char s[])
{
    if (s[0] == '\0')
        return;
    printf("%c", s[0]);
    imprime(&s[1]);
}

int main()
{
    char msg[257];
    fgets(msg, 256, stdin); //ou scanf("%100[^\n]%*c",msg);
    imprime(msg);
    printf("%c", msg[0]);
    return 0;
}