#include <stdio.h>
#include <stdlib.h>

#define AVISO(msg) fprintf(stdout, "AVISO: %s\n", #msg)
#define ERRO(msg) fprintf(stderr, "ERRO: %s\n", #msg)

void le_array(int *a, int n) { //poderia ser "int a[]" ao invés de "int *a"
	AVISO("Vixe! Ainda não fiz a função 'le_array'");
}

void imprime_array(int *a, int n) {
	AVISO("Vixe! Ainda não fiz a função 'imprime_array'");
}

void troca(int x, int y) {
	AVISO("Vixe! Ainda não fiz a função 'troca'");
}

void funcao_misteriosa(int a[], int n) {
	int i, j, temp;
	for(i = 0; i < n-1; i++){
		int posMin = i;
    	for (j = (i+1); j < n; j++) {
	    	if(a[j] < a[posMin]) {
         		posMin = j;
			}
		}
		if (a[i] != a[posMin]) {
			troca(a[i], a[posMin]);
		}
	}

}
int main() {
	int n;
	printf("Digite o numero de valores a ser lido: ");
	scanf("%d", &n);
	int *valores = malloc(n*sizeof(int));
	if (valores == NULL) {
		ERRO("Socorro! malloc devolveu NULL!");
		exit(EXIT_FAILURE);
	}
	printf("Digite %d valores\n", n);
	le_array(valores, n);
	funcao_misteriosa(valores, n);
	printf("Os %d valores apos a funcao misteriosa\n", n);
	imprime_array(valores, n);

	return 0;
}