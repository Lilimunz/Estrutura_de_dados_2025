#include "fila.h"

t_fila * constroi_fila (int capacidade){
    t_fila * fila = (t_fila *) malloc (sizeof(t_fila));
    fila->capacidade = capacidade;
    fila->primeiro = 0;
    fila->ultimo = 0;
    fila->ocupacao = 0;
    fila->dados = (int *) malloc (capacidade * sizeof(int)); //aloca o vetor de dados - o próprio vetor mesmo
    return fila;
}

int fila_vazia (t_fila *fila){
    if(fila->ocupacao == 0) return 1;
    return 0;
}

int fila_cheia (t_fila *fila){
    if(fila->ocupacao == fila->capacidade) return 1;
    return 0;
}

int proxima (int pos, int capacidade){
    return (pos+1) % capacidade;
}

int enfileira (int i,  t_fila *fila){
    if(fila_cheia(fila)) return 0;
    fila->dados[fila->ultimo] = i;
    fila->ultimo = proxima(fila->ultimo, fila->capacidade);
    fila->ocupacao++;
    return 1;
}

int desenfileira (int *i, t_fila *fila){
    if(fila_vazia(fila)) return 0;
    *i = fila->dados[fila->primeiro];
    fila->primeiro = proxima(fila->primeiro, fila->capacidade);
    fila->ocupacao--;
    return 1;
}

void mostra_fila (t_fila *fila){
    if(fila_vazia(fila)){
        printf("A fila esta vazia\n");
    }
    else {
        int i = fila->primeiro;
        do {
            printf("%d ", fila->dados[i]);
            i = proxima(i, fila->capacidade);
        } while (i!= fila->ultimo);
    }
    printf("\n");
}

void mostra_vetor (t_fila *fila){
    if(fila_vazia(fila)){
        for (int i=0; i < fila->capacidade; i++){
            printf("_ ");
        }
    }
    else if (fila_cheia(fila)){
        for(int i=0; i < fila->capacidade; i++){
            printf("%d ", fila->dados[i]);
        }
    }
    else if ( fila->primeiro < fila->ultimo){
        for(int i=0; i< fila->primeiro; i++){
            printf("_ ");
        }
        for(int i = fila->primeiro; i< fila->ultimo; i++){
            printf("%d ", fila->dados[i]);
        }
        for(int i=fila->ultimo; i<fila->capacidade; i++){
            printf("_ ");
        }
    }
    else {
        for(int i=0; i< fila->ultimo; i++){
            printf("%d ", fila->dados[i]);
        }
        for(int i = fila->ultimo; i< fila->primeiro; i++){
            printf("_ ");
        }
        for(int i=fila->primeiro; i<fila->capacidade; i++){
            printf("%d ", fila->dados[i]);
        }
    }
    printf("\n");
}