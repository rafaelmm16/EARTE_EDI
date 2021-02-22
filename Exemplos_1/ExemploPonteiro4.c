#include <stdio.h>
#include <stdlib.h>

    int main () {
    int * p1;
    * p1 = 10 ; // Em qual endere ço o valor 10 ser á armazenado ?

    printf (" End. p1 = %p\n", & p1 ) ;
    printf (" End. apontado por p1 = %p\n", p1 ) ;
    printf (" Valor do end. apontado por p1 = %d\n", * p1 ) ;

    return 0 ;
}
