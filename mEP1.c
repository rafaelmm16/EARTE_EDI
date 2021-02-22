#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int k=0;
    int n=0;
    int *v;

    int max, min, aux;
    int j=0;

    int i=0, soma=0, somaPart=0;

    //primeira entrada, quantidade
    if(n<=1 || n<=pow(10,9))
    {
        scanf("%d", &n);
    }

    v = malloc ( n * sizeof (int ) ) ;
    //segunda entrada, valor
    for(i=0; i<n; i++)
    {
        scanf("%d ", &v[i]);
    }
    
    //terceira entrada, dias
    if (k<=1 || k<=n)
    {
        scanf("%d", &k);
    }
    
    //maior elemento
    max=v[0];
    for(i=0; i<n; i++){
        if(max<v[i])
        {
            max = v[i];
            j = i;
        }   
    }

    //percorrendo o vetor a partir
    //do maior elemento.
    //de trás ate o inicio do vetor
    for (i = j; i >= 0; i--)
    {
        if(k>0){
            soma+=v[i];
            k--;
        }
        else
        break;
    }

    //verifica o k>0
    //e depois do maior elemento
    //até a contagem do somatorio de k
    if(k>0){
        for (i = j+1; i < n; i++)
        {
            if(k>0){
                soma+=v[i];
                k--;
            }
            else
            break;
        }
    }

    printf("%d", soma);
    printf("\n");

    free(v);
 return 0;
}