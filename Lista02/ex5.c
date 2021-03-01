#include <stdio.h>
#include <stdlib.h>

double **cria(int n) {
    //Função que cria uma matriz simátrica n x n
    //Essa função também deve inicializar todos os elementos com 0
    //Retono: ponteiro para a matriz 
    double **m;
    m= (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++){
        m[i]=(double*)malloc(n* sizeof(double));
        for(int j=0; j<n; j++){
            m[i][j]=0;
        }
    }
    return m;
}

void modifica(double **m, int i, int j, int n, double valor){
    //Modifica o elemento m[i][j], atribuindo 'valor' a posição (i, j)
    //Lembre-se que a matriz é simetrica, então cuidado para não acessar 
    //um elemento que não esteja explicitamente alocado
    //Verifique se i e j são válidos. Caso não sejam, imprima uma 
    // mensagem de erro.

    if(i>=n || j>=n || i<0 || j<0 || m[i]==NULL){
        printf("Erro.\n");
    }
    else
        m[i][j]=valor;    
      
}

double acessa(double **m, int i, int j, int n) {
    //Retorna o elemento na posição (i, j)
    //Cuidado para não acessar um elemento que não
    // esteja explicitamente alocado
    //Verifique se i e j são válidos. Caso não sejam, imprima uma
    // mensagem de erro e encerre o programa com exit(1) 
    
    if(i>=n || j>=n || i<0 || j<0 || m[i]==NULL){
        printf("Erro.\n");
        exit(1);
    }
    else{
       return m[i][j];
    }
   
   
   
}

void imprime(double **m, int n){
    //Função que imprime a matriz
    //Essa função deve imprimir a matriz de forma natural
    //independente de como ela está sendo armazenada.
    //Ou seja, deve ser impressos os n x n elementos na tela.
    //Imprima os valores com 2 casas decimais

    for(int i=0 ; i < n ; i++ ) {
       for(int j=0; j<n; j++){
            printf("%0.2lf ", m[i][j]);
        }
        printf("\n");
   }
}

int main() {
    int n = 10;
    double **m = cria(n);
    imprime(m, n);
    modifica(m, 0, 0, n, 2.5);
    modifica(m, 0, 1, n, 3.2);
    modifica(m, 0, 2, n, 6.0);
    modifica(m, 0, 9, n, 8.5);
    printf("\nMatriz modificada\n");
    imprime(m, n);
    printf("m[%d][%d] = %.2lf\n", 0, 9, acessa(m, 0, 9,n));
    printf("m[%d][%d] = %.2lf\n", 9, 0, acessa(m, 9, 0, n));

   for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            modifica(m, i, j, n, 3.14);
        }
    }
    imprime(m, n);

    modifica(m, 0, 10, n, -1); //Deve gerar um erro e não modificar a matriz
    imprime(m, n);

    printf("m[%d][%d] = %.2lf\n", 10, 0, acessa(m, 10, 0, n)); //Gera erro e encerra o programa*/

    return 0;
}
