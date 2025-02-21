#include <stdio.h>
#include <stdlib.h>

int main () {
    //int v[1000000]; //para alocação estática tem um maximo da memória, não é expansiva
    int *v = (int *) malloc (100000000 * sizeof(int));
    
    //alocação dinamica tem a memoria mais expansiva - agora é possivel alocar muito mais memoria
    printf("foi");
    return 0;
}