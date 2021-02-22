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
    //Ler a quantidade de funcionários da empresa;
    printf("Quantidade de funcionarios:");
    scanf("%d", &n);

//Alocar dinamicamente a memória para armazenar os dados desses funcionários;
    VetorF = (Funcionario*) malloc(n * sizeof(Funcionario));
    if (VetorF == NULL) {
        printf(">>> Sem memória <<<\n");
        exit(1);
    }
    //Para cada funcionário, ler o seu código, quantos dias trabalhou e as horas trabalhadas de cada dia;
    for (int i = 0; i < n; i++) {

        printf("--- Funcionario %d --- \n", i+1);
        printf("Codigo:");
        scanf("%d",&VetorF[i].codigo);
        printf("Quantidade de dias trabalhados:");
        scanf("%d",&VetorF[i].qtd_dias_trabalhados);
        VetorF[i].horas_trabalhadas = (int*) malloc (VetorF[i].qtd_dias_trabalhados*sizeof(int)); //31 = dias no mes, máximo
        printf("Horas trabalhadas em cada dia: ");
        for (int i=0; i<VetorF[i].qtd_dias_trabalhados; i++) {
            scanf("%d",&VetorF[i].horas_trabalhadas);

        }
    }
     printf ("--- Relatorio Final ---\n");
     printf ("Funcionario - Horas Trabalhadas - Salário\n");
     for (int i = 0; i < n; i++) {
            for (int j =0; j<VetorF[i].qtd_dias_trabalhados;j++){
                SomaHora+= VetorF[i].horas_trabalhadas[j];
            }
            //Sabendo que a empresa paga R$25,00/hora, imprimir o valor que cada funcionário deve receber;
            aux = SomaHora*25;
            printf ("%d     -     %d       -    R$%.2f",VetorF[i].codigo, SomaHora, aux);
            SomaFunc+=aux;
            SomaHora =0;
            aux = 0;
     }
     //Imprimir o valor total gasto com funcionários pela empresa;
     printf("\n Total pago aos funcionarios: R$%.2f \n", SomaFunc);

//Desalocar toda a memória alocada
    free(VetorF);

    return 0;
}
