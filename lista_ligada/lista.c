#include "lista.h"

void constroi_lista (t_lista *lista){ //nao precisa colocar o nome da variavel - mas pode 
    lista->primeiro = lista->ultimo = NULL;
}

int lista_vazia (t_lista *lista){
    if (lista->primeiro == NULL) 
        return 1;
    return 0; //return !lista->primeiro; - da pra deixar assim
}

void insere_inicio (int i, t_lista *lista) {
    t_no * novo = constroi_no(i);
    if(lista_vazia(lista)){
        lista->ultimo = novo;
    }
    else {
        novo->prox = lista->primeiro;
    }
    lista->primeiro = novo;
}

int remove_inicio (t_lista *lista) {
    if(lista_vazia(lista)) return -1;
    int temp = lista->primeiro->info;
    t_no *aux = lista->primeiro;
    lista->primeiro = lista->primeiro->prox;
    if(lista->primeiro == NULL){//esvaziou a lista
        lista->ultimo = NULL;
    }
    free(aux);
    return temp;
}

void mostra_lista (t_lista *lista){
    if(lista_vazia(lista)){
        printf  ("lista vazia\n");
    }
    else {
        t_no *runner = lista->primeiro;
        while (runner != NULL){ // for (runner = lista->primeiro; runner != NULL; runner = runner->prox)
            printf("[%d] -> ", runner->info);
            runner = runner->prox;
        }
        printf("\\\\\n");
    }
}

void insere_fim (int i, t_lista *lista){
    t_no *novo = constroi_no(i);
    if(lista_vazia(lista)){
        lista->primeiro = novo;
    }
    else {
        lista->ultimo->prox = novo;
    }
    lista->ultimo = novo;
}

int remove_fim (t_lista *lista){
    //tratamento de particularidades

    //cenário 1: lista vazia
    if(lista_vazia(lista)) return -1;
    //cenario 2: lista tem 1 elemento só
    int temp;
    if(lista->primeiro == lista->ultimo){
        temp = lista->primeiro->info;
        free(lista->primeiro);
        lista->primeiro = lista->ultimo = NULL; // liberou e zerou tudo
        //return temp opcional - se num tivesse else - colocar no final do laço
    }
    else{
        //cenário 3: lista tem mais que um
        t_no *runner = lista->primeiro;
        while(runner->prox != lista->ultimo){ //encontrar o penúltimo
            runner = runner->prox; //so caminha
        }
        temp = lista->ultimo->info;
        free(lista->ultimo);
        //atualizar todos os ponteiros
        runner->prox = NULL;
        lista->ultimo = runner;
    }
    return temp;
}

int conta_elemento (t_lista *lista) {
    int count = 0;
    if(lista_vazia(lista)) return -1;
    
    t_no *runner = lista->primeiro;
    while(runner != NULL){
        count++;
        runner = runner->prox;
    }
    return count;
}

int encontra_maior (t_lista *lista) {
    // b)Encontrar o maior elemento da lista
    if(lista_vazia(lista)) return -1;
    int maior = lista->primeiro->info;
    int temp;

    t_no *runner = lista->primeiro;
    while(runner != NULL){
        temp = runner->info;
        if(temp > maior){
            maior = temp;
        }
        runner = runner->prox;
    }
    return maior;
}

int encontra_x (t_lista *lista, int x) {
// c) Encontrar um elemento x na lista
    if(lista_vazia(lista)) return -1;
    int temp;

    t_no *runner = lista->primeiro;

    while(runner != NULL){
        temp = runner->info;
        if(temp == x) return temp;
        runner = runner->prox;
    }
    return -1;
}

int conta_x (t_lista *lista, int x) {
// d) Verificar quantas vezes o x aparece na lista
    if(lista_vazia(lista)) return -1;
    int count = 0;
    int temp;

    t_no *runner = lista->primeiro;

    while(runner != NULL){
        temp = runner->info;
        if(temp == x){
            count++;
        }
        runner = runner->prox;
    }
    return count;
}

void lista_pos (t_lista *lista, int x) {
// e) Criar uma lista com as posições que o x aparece na lista
    if(lista_vazia(lista)) -1;

    int temp;
    int count_pos = 0;
    t_no *runner = lista->primeiro;
    
    printf("%d aparece nas posicoes ", x);
    while(runner != NULL){
        temp = runner->info;
        if(temp == x){
            printf("[%d] -> ", count_pos);
        }
        count_pos++;
        runner = runner->prox;
    }
}