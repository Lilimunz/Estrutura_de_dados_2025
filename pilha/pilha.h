#include <stdio.h>
#include <stdlib.h>
//definições de tipo, protótipos
typedef struct {
    int * dados;
    int topo;
    int capacidade;
} t_pilha;

void constroi_pilha (int capacidade, t_pilha *p);
int push (int i, t_pilha *p);
int pop (t_pilha *p, int *removido);
int pilha_vazia (t_pilha *p);
int pilha_cheia (t_pilha *p);
void exibe_pilha (t_pilha *p);
void inverte_pilha(t_pilha *p);
