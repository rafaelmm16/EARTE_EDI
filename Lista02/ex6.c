//tive dificuldades na hora de trabalhar com char
//pois uma soma de char, pode dar até 2 numeros na elevação
//da proxima soma

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *soma(char *n1, char *n2){
    //Função que recebe dois array de char contendo dígitos
    //A função deve calcular e retornar um array de char contendo
    // a soma desses números

    int a, i, maisUm=0;
    char *res;
    res = (char*)malloc(sizeof(char)*11);
    for(i=9;i>=0;i--){
       // printf("to aqui\n");
        if(maisUm>0)
            a = maisUm;
        else
            a = 0;
        if(isAnumber(n1[i]))
            a+=(n1[i]-48);
        if(isAnumber(n2[i]))
            a+=(n2[i]-48);
            //printf("%d", a);
        if(a>9){
            maisUm = a/10;
            res[i] = (a%10)+48;
        }
        else{
            printf("%d\n", a);
            maisUm = 0;
            res[i] = a+48;
        }
        
    }
    printf("%s", res);
return res;
}

int isAnumber(int c){
    if(c>47 && c<58)
        return 1;
    else
        return 0;
}

int main() {    
    char *numero1 = malloc(10*sizeof(char));
    char *numero2 = malloc(10*sizeof(char));
    printf("Digite o primeiro número: ");
    scanf("%s", numero1);
    printf("Digite o segundo número: ");
    scanf("%s", numero2);
    //printf("%s + %s = %s\n", numero1, numero2, soma(numero1, numero2));
    soma(numero1, numero2);
    return 0;
}
