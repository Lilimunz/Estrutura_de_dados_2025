#include <time.h>
#include "fila.h"

int main (){
    t_fila *fila;
    fila = constroi_fila(8);
    int a;
    srand(time(0));
    do{
        if(rand() % 2){ //se é par enfileira
        enfileira(rand() % 10, fila);
        }
        else { // se for impar desenfileira
            desenfileira(&a, fila);
        }
        mostra_fila(fila);
        mostra_vetor(fila);
    } while(!fila_vazia(fila));

    return 0;
}