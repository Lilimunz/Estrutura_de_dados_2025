#include "estacionamento.h"

void constroi_pilha(int capacidade, t_estacionamento *p) {
    p->topo = 0;
    p->capacidade = capacidade;
}

int estacionamento_vazio(t_estacionamento *p) {
    return (p->topo == 0);
}

int estacionamento_cheio(t_estacionamento *p) {
    return (p->topo == p->capacidade);
}

int entra_carro(t_estacionamento *p, char placa[]) {
    if (estacionamento_cheio(p)) return 0;
    strcpy(p->carro[p->topo].placa, placa);
    p->topo++;
    return 1;
}

int sai_carro(t_estacionamento *p) {
    if (estacionamento_vazio(p)) return 0;
    p->topo--;
    return 1;
}
int manobrista(t_estacionamento *p, char placa[]) {
    // Cria uma pilha auxiliar 
    t_estacionamento aux;
    constroi_pilha(10, &aux);
    int manobras = 0;
    int encontrado = 0;

    while (!estacionamento_vazio(p) && !encontrado) {
        // Pega o carro do topo da pilha
        t_carro carro = p->carro[p->topo - 1];
        // Verifica se é o carro procurado
        if (strcmp(carro.placa, placa) == 0) {
            // Remove o carro do estacionamento
            sai_carro(p);
            // Marca como encontrado
            encontrado = 1;
        } 
        else{
            // Se não for o carro, move para a pilha auxiliar
            sai_carro(p);
            entra_carro(&aux, carro.placa);
            manobras++;
        }
    }
    // Restaura a pilha original
    while (!estacionamento_vazio(&aux)) {
        t_carro temp = aux.carro[aux.topo - 1];
        sai_carro(&aux);
        entra_carro(p, temp.placa);
    }
    // Retorna o número de manobras se encontrou, ou -1 se não encontrou
    return (encontrado ? manobras : -1);
}