#include <stdio.h>
#include <stdlib.h>

void troca (int x , int y ) {
    int aux ;
    aux = x ;
    x = y ;
    y = aux ;
}

int main () {
    int a , b ;
    a = 10 ;
    b = 20 ;
    printf (" Antes da troca \n") ;
    printf ("a = %d\n", a ) ;
    printf ("b = %d\n", b ) ;

    troca (a , b) ;

    printf (" Depois da troca \n") ;
    printf ("a = %d\n", b ) ;
    printf ("b = %d\n", a ) ;

    return 0 ;
}