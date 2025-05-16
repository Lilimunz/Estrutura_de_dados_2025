#include "fila.h"

int main (){
    t_fila *fila;
    int *pi = (int *) malloc (sizeof(int));
    fila = constroi_fila(5);
    printf("fila construida\n");
    mostra_fila(fila);

    if(enfileira(10, fila)){ //utilizando os retornos
        printf("Insercao realizada com sucesso\n");
    }
    else {
        printf("Falha na insercao, fila cheia\n");
    }
    //enfileira (20, fila); //ja é um ponteiro
    enfileira(20, fila);
    printf("10 e 20 enfileirado\n");
    mostra_fila(fila);

    if(desenfileira(pi, fila)){
        printf("%d saiu da fila\n", *pi);//derreferencia - conteudo de pi
    }
    else{
        printf("Falha no desenfileiramento, fila vazia\n");
    }
    mostra_fila(fila);
    enfileira(30, fila);
    enfileira(40, fila);
    printf("30 e 40 enfileirados\n");
    mostra_fila(fila);
    return 0;
}