#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo ; // codigo do funcionario
    int qtd_dias_trabalhados ; // qtd de dias que o funcionario trabalhou
    int *horas_trabalhadas ; // horas trabalhadas em cada dia pelo func .
} Funcionario;


int main() {
    Funcionario* VetorF;
    int n=0;
    float SomaFunc =0, aux =0;
    int SomaHora =0;
    //Ler a quantidade de funcion�rios da empresa;
    printf("Quantidade de funcionarios:");
    scanf("%d", &n);

//Alocar dinamicamente a mem�ria para armazenar os dados desses funcion�rios;
    VetorF = (Funcionario*) malloc(n * sizeof(Funcionario));
    if (VetorF == NULL) {
        printf(">>> Sem mem�ria <<<\n");
        exit(1);
    }
    //Para cada funcion�rio, ler o seu c�digo, quantos dias trabalhou e as horas trabalhadas de cada dia;
    for (int i = 0; i < n; i++) {

        printf("--- Funcionario %d --- \n", i+1);
        printf("Codigo:");
        scanf("%d",&VetorF[i].codigo);
        printf("Quantidade de dias trabalhados:");
        scanf("%d",&VetorF[i].qtd_dias_trabalhados);
        VetorF[i].horas_trabalhadas = (int*) malloc (VetorF[i].qtd_dias_trabalhados*sizeof(int)); //31 = dias no mes, m�ximo
        printf("Horas trabalhadas em cada dia: ");
        for (int i=0; i<VetorF[i].qtd_dias_trabalhados; i++) {
            scanf("%d",&VetorF[i].horas_trabalhadas);

        }
    }
     printf ("--- Relatorio Final ---\n");
     printf ("Funcionario - Horas Trabalhadas - Sal�rio\n");
     for (int i = 0; i < n; i++) {
            for (int j =0; j<VetorF[i].qtd_dias_trabalhados;j++){
                SomaHora+= VetorF[i].horas_trabalhadas[j];
            }
            //Sabendo que a empresa paga R$25,00/hora, imprimir o valor que cada funcion�rio deve receber;
            aux = SomaHora*25;
            printf ("%d     -     %d       -    R$%.2f",VetorF[i].codigo, SomaHora, aux);
            SomaFunc+=aux;
            SomaHora =0;
            aux = 0;
     }
     //Imprimir o valor total gasto com funcion�rios pela empresa;
     printf("\n Total pago aos funcionarios: R$%.2f \n", SomaFunc);

//Desalocar toda a mem�ria alocada
    free(VetorF);

    return 0;
}
