#include "estacionamento.h"

void constroi_pilha(t_estacionamento *p) {
    p->topo = 0;
}

int estacionamento_vazio(t_estacionamento *p) {
    return (p->topo == 0);
}

int estacionamento_cheio(t_estacionamento *p) {
    return (p->topo == MAX_CARROS);
}

int entra_carro(t_estacionamento *p, char placa[]) {
    if (estacionamento_cheio(p)) return 0;
    strcpy(p->carro[p->topo].placa, placa);
    p->carro[p->topo].manobras = 0;
    p->topo++;
    return 1;
}

int sai_carro(t_estacionamento *p) {
    if (estacionamento_vazio(p)) return 0;
    p->topo--;
    return 1;
}

int procurar_carro(t_estacionamento *p, char *placa){
    for (int i = 0; i < p->topo; i++) {
        if (strcmp(p->carro[i].placa, placa) == 0) {
            return i;
        }
    }
    return -1;
}

int manobrista(t_estacionamento *p, char placa[]) {
    // Cria uma pilha auxiliar para guardar os carros 
    t_estacionamento aux;
    constroi_pilha(&aux);
    int pos = procurar_carro(p, placa);
    if (pos == -1) return 0;
    // Remove os carros acima do que queremos tirar
    while (p->topo > pos + 1) {
        p->topo--;
        // Incrementa o contador de manobras do carro que está sendo movido
        p->carro[p->topo].manobras++;
        // Move para a pilha temporária
        aux.carro[aux.topo] = p->carro[p->topo];
        aux.topo++;
    }
    sai_carro(p);
    printf("Carro %s saiu com %d manobras.\n", p->carro[p->topo].placa, p->carro[p->topo].manobras);
    // Devolve os carros manobrados
    while (aux.topo > 0) {
        aux.topo--;
        p->carro[p->topo] = aux.carro[aux.topo];
        p->topo++;
    }
    
    return 1;
}