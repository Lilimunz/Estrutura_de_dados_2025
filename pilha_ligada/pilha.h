#include "no.h"

typedef struct {
    t_no *topo;
} t_pilha;

void constroi_pilha (t_pilha *); //nao precisa colocar o 
int pilha_vazia (t_pilha *);
void push (int, t_pilha *);
int pop (t_pilha *, int *);
void exibe_pilha (t_pilha *); 
