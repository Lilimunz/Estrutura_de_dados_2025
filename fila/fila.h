#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * dados;
    int primeiro, ultimo;
    int capacidade, ocupacao;
} t_fila;

t_fila * constroi_fila (int);
int fila_vazia (t_fila *);
int fila_cheia (t_fila *);
int enfileira (int , t_fila *);
int desenfileira (int *, t_fila *);
void mostra_fila (t_fila *);
void mostra_vetor (t_fila *);