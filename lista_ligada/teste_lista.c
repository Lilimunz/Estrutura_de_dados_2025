#include "lista.h"

int main () {
    t_lista lista;
    constroi_lista(&lista);

    int x;
    int i;
    int encontrado = 89;

    // for(int i=1; i<=10; i++){
    //     insere_inicio(i, &lista); //empilhamento    
    // }
    insere_inicio(89, &lista); 
    insere_inicio(9, &lista);
    insere_inicio(8, &lista);
    insere_inicio(5, &lista);
    insere_inicio(8, &lista);
    insere_inicio(87, &lista);
    insere_inicio(89, &lista);
    insere_inicio(2, &lista);
    insere_inicio(20, &lista);
    insere_inicio(89, &lista); 
     

    mostra_lista(&lista);

    printf("o numero digitado foi encontrado %d vez(es)\n", conta_x(&lista, encontrado));

    encontrado, lista_pos(&lista, encontrado);
    
    printf("existem %d elementos na lista.\n",conta_elemento(&lista));

    printf("O maior elemento encontrado na lista foi o %d.\n", encontra_maior(&lista));

    x = encontra_x(&lista, 10);
    if(x != -1){
        printf("O %d foi encontrado", x);
    }
    else {
        printf("O elemento digitado nao foi encontrado", x);
    }


    while(!lista_vazia(&lista)){
        printf("%d saiu do inicio\n", remove_inicio(&lista)); //desempilhar
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