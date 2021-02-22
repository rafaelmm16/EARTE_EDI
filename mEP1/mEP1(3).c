#include <stdio.h>
#include <stdlib.h>

int main(){

  int k = 0, n = 0, max = 0, i = 0, j = 0;
  int soma = 0, q=0, hit = 0, somaf=0, somat=0;
  int *v = 0;

  //primeira entrada, quantidade
  scanf("%d", &n);

  v = malloc ( n * sizeof (int ) ) ;
  //segunda entrada, valor
  for(i=0; i<n; i++)
  {
    scanf("%d ", &v[i]);
  }

  //terceira entrada, dias
  scanf("%d", &k);

  for(i = 0; i < n; i++){
    if(v[i] > max)
    {
      max = v[i];
      hit = i;
    }
  }

  q = hit - k;
  if (q < 0) q = 0;

  for(i=0; i<=hit; i++)
  {
    for(j=q; j<k+q; j++)
    {
      soma += v[j];
    }
    if (soma > somaf) somaf = soma;
    else if(q == 0) somaf = soma;
    soma = 0; q++;
    if((q + k - 1) >= n) break;
  }
    
  printf("%d\n", somaf);

  free(v);

 return 0;
}