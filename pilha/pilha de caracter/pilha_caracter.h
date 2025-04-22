#include <stdio.h>
#include <stdlib.h>
//definições de tipo, protótipos
typedef struct {
    char * dados;
    int topo;
    int capacidade;
} t_pilha_caracter;

void constroi_pilha (int capacidade, t_pilha_caracter *p);
int push (char i, t_pilha_caracter *p);
int pop (t_pilha_caracter *p, char *removido);
int pilha_vazia (t_pilha_caracter *p);
int pilha_cheia (t_pilha_caracter *p);
void exibe_pilha (t_pilha_caracter *p);
void inverte_pilha(t_pilha_caracter *p);
