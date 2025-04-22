#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char placa[8]; 
} t_carro;

typedef struct {
    t_carro carro[10];
    int topo;
    int capacidade;
} t_estacionamento;

void constroi_pilha(int capacidade, t_estacionamento *p);
int estacionamento_vazio(t_estacionamento *p);
int estacionamento_cheio(t_estacionamento *p);
int entra_carro(t_estacionamento *p, char placa[]);
int sai_carro(t_estacionamento *p);
int manobrista(t_estacionamento *p, char placa[]);