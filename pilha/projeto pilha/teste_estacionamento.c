#include "estacionamento.h"

int main() {
    t_estacionamento estacionamento;
    constroi_pilha(10, &estacionamento);
    char comando;
    char placa[8]; 

    while (scanf(" %c %s", &comando, placa) != EOF) {
        if (comando == '0') {
            if (entra_carro(&estacionamento, placa)) {
                printf("Carro %s estacionado.\n", placa);
            } 
            else {
                printf("Estacionamento cheio. Carro %s foi embora.\n", placa);
            }
        } 
        else if (comando == '1') {
            int manobras = manobrista(&estacionamento, placa);
            if (manobras == -1) {
                printf("Carro %s nao encontrado no estacionamento.\n", placa);
            } 
            else {
                printf("Carro %s saiu com %d manobra(s).\n", placa, manobras);
            }
        }
    }
    return 0;
}