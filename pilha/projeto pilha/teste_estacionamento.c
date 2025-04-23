#include "estacionamento.h"

int main() {
    t_estacionamento estacionamento;
    constroi_pilha(&estacionamento);

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
        } else if (comando == '1') {
            if (!manobrista(&estacionamento, placa)) {
                printf("Carro %s nao encontrado no estacionamento.\n", placa);
            }
        }
    }

    return 0;
}