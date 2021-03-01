#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome [ 30 ];
    int matricula ;
} Aluno ;

int main () {
    Aluno * x ;
    Aluno y ;

    x = & y;
    x -> matricula = 2031 ;

    printf ("%d\n", y . matricula ) ;

    return 0;
}
