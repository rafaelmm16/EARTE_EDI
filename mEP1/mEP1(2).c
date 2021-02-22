#include <stdio.h>
#include <stdlib.h>

int main(){

    int k = 0, n = 0, max = 0, q=0, i = 0, j = 0, soma = 0;
    int hit, somaf=0, somat=0;
    int *v = 0;
    
    //primeira entrada, quantidade
    //if(n<=1 || n<=pow(10,9))
    //{
    scanf("%d", &n);
    //}

    v = malloc ( n * sizeof (int ) ) ;
    //segunda entrada, valor
    for(i=0; i<n; i++)
    {
        scanf("%d ", &v[i]);
    }
    
    //terceira entrada, dias
    //if (k<=1 || k<=n)
    //{
    scanf("%d", &k);
    //}
    
    //maior elemento
    //max = v[0];
    for(i = 0; i < n; i++){
        if(v[i] > max)
        {
            max = v[i];
            j = i;
        }   
    }

soma += v[j]; // Adiciona o maior a soma +1 dia
    q = j; //Iguala para comparação
    hit = j;
    
    hit++; // coloca j no proximo indice
    q--; // coloca q no indice anterior

    for (i=0; i < k - 1; i++)
    {
        if(q < 0)
        {
          soma += v[hit];
          hit++;
          // printf("1- ");
        }else if(hit >= n)
        {
          soma += v[q];
          q--;
          // printf("2- ");
        }else if(hit >= n && q < 0)
        {
          // printf("3- ");
          break;
        }else if(v[q] < v[hit])
        {
          soma += v[hit];
          hit++;
          // printf("4- ");
        }else
        {
          soma += v[q];
          q--;
          // printf("5- ");
        }
         //printf("%d\n", soma);
    }

    q = j;hit = j;
    if(j+k >= n) hit = n - k;
    if(j-k < 0) q = k - 1;

    for(i=0; i < k; i++)
    {
      somaf += v[hit];
      somat += v[q];
      hit++;q--;
    }
    //printf("%d\n", soma);
    //printf("%d\n", somaf);
    //printf("%d\n", somat);
    if(somaf > soma) soma = somaf;
    else if (somat > soma) soma = somat;

    printf("%d\n", soma);

    free(v);

 return 0;
}