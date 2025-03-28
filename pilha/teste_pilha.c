#include "pilha.h"

//para converter um n°base 10 para base bunaria, dividimos por 2 e tomamos o resto, enquanto for possivel dividir. Aí tomamos os restos na ordem inversa
t_pilha converte_base (int n){//usando pilha pra fazer alguma coisa - aplicação
    t_pilha p;
    constroi_pilha(30, &p);//inicializa
    while (n > 1){ //aplica o algoritmo; enquanto for maior que 1 empilha e divide, até não satisfazer a condução
        push(n%2, &p);
        n = n / 2;
    }
    push(n, &p);
    return p;
}

int main () {
    t_pilha pilha;
    constroi_pilha(10, &pilha);
    exibe_pilha(&pilha);

    push(10, &pilha); //por referencia
    push(20, &pilha);
    if (push(30, &pilha)){
        printf("30 empilhado com sucesso\n-----------------\n"); //não estamos disperdicando o return do pilha.c
    }
    else {
        printf("pilha cheia, nao foi possivel empilhar\n");
    }
    exibe_pilha(&pilha);

    int aux;
    if (pop(&pilha, &aux)){
        printf("%d foi desempilhado\n", aux);
    }
    else {
        printf("pilha vazia, nao foi possivel desempilhar\n");
    }
    exibe_pilha(&pilha);

    int i = 1;
    while (push(i, &pilha)) { //da para fazer while (push(i++, &pilha)) - que ai ele incrementa e depois empilha
        i++;
        exibe_pilha(&pilha);
    }

    while(pop(&pilha, &aux)){
        printf("%d foi desempilhado\n------------------\n", aux);
    }
    exibe_pilha(&pilha);

    push(10, &pilha); //por referencia
    push(20, &pilha);
    push(30, &pilha);
    exibe_pilha(&pilha);
    inverte_pilha(&pilha); 
    converte_base(13);
    return 0;
}