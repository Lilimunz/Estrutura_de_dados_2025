#include "lista.h"

int main () {
    t_lista lista;
    constroi_lista(&lista);

    for(int i=1; i<=10; i++){
        insere_inicio(i, &lista); //empilhamento
    }
    mostra_lista(&lista);

    while(!lista_vazia(&lista)){
        printf("%d saiu do inicio\n", remove_inicio(&lista));
        mostra_lista(&lista);
    }
    for (int i=1; i<=10; i++){
        insere_fim(i, &lista);//preserva a ordem - enfileiramento
    }
    mostra_lista(&lista);

    while(!lista_vazia(&lista)){
        printf("%d saiu do fim\n", remove_fim(&lista));//desenfileirar
        mostra_lista(&lista);
    }
    
    return 0;
}