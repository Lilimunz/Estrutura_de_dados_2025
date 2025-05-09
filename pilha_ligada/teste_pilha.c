#include "pilha.h"

t_pilha converte_base(int n){
    t_pilha p;
    constroi_pilha(&p);
    while (n > 1){
        push(n % 2, &p);
        n = n / 2;
    }
    push(n, &p);
    return p;
}

int main () {
    t_pilha pilha;
    constroi_pilha(&pilha);
    exibe_pilha(&pilha);

    push(10, &pilha); 
    push(20, &pilha);
    push(30, &pilha);
    exibe_pilha(&pilha);

    int aux;
    if (pop(&pilha, &aux)){
        printf("%d foi desempilhado\n", aux);
    }
    else {
        printf("pilha vazia, nao foi possivel desempilhar\n");
    }
    exibe_pilha(&pilha);

    while(pop(&pilha, &aux)){
        printf("%d foi desempilhado\n------------------\n", aux);
    }
    exibe_pilha(&pilha);

    push(10, &pilha); //por referencia
    push(20, &pilha);
    push(30, &pilha);
    exibe_pilha(&pilha);

    pilha = converte_base(64);
    exibe_pilha(&pilha);
    pilha = converte_base(13);
    exibe_pilha(&pilha);
    return 0;
}