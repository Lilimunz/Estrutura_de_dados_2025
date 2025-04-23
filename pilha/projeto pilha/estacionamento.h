#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARROS 10

typedef struct {
    char placa[8];
     int manobras;
} t_carro;

typedef struct {
    t_carro carro[MAX_CARROS];
    int topo;
} t_estacionamento;

void constroi_pilha(t_estacionamento *p);
int estacionamento_vazio(t_estacionamento *p);
int estacionamento_cheio(t_estacionamento *p);
int entra_carro(t_estacionamento *p,char *placa);
int sai_carro(t_estacionamento *p);
int procurar_carro(t_estacionamento *p, char *placa);
int manobrista(t_estacionamento *p, char placa[]);