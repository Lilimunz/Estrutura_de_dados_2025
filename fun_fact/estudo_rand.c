#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    long int tempo = time(0);
    printf("Valor retornado pelo time(0): %ld\n", tempo);
    srand(tempo);
    int m = rand();
    int n = rand();
    printf("m = %d\nn = %d\n", m, n);
    
    printf("de 0 a 10: %d\n", rand()%11);

    return 0;
}