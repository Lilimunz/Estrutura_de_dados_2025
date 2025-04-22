#include "pilha_caracter.h"

void constroi_pilha (int capacidade, t_pilha_caracter *p) {
    p->dados = (char *) malloc (capacidade); //da pra deixar assim - pq char é apenas um byte
    p->topo = 0;
    p->capacidade = capacidade;
}

int pilha_vazia (t_pilha_caracter *p){
    if(p->topo == 0) return 1;
    return 0; //pode colocar else ou não
    //return p-topo == 0; - joga o teste pro compilador
    //return !p->topo; - negação pq na pilha ta verdadeiro
}

int pilha_cheia (t_pilha_caracter *p){
    if(p->topo == p->capacidade) return 1;
    return 0;
    //return p->topo == p->capacidade; - ele faz o teste e devolve
}

int push (char i, t_pilha_caracter *p) {
    if (pilha_cheia(p)) return 0;
        p->dados[p->topo] = i; //pode incrementar depois com p->dados[p->topo++] = i mas tem que apagar a linha de p->topo++;
        p->topo++; // como se tivesse com (p->topo)++ porque seta tem preferencia que incremento
        return 1;
}

int pop (t_pilha_caracter *p, char *removido) {
    if(pilha_vazia(p)) return 0; //limoa o caminho o que sobrou vai liso
    p->topo--; //tem como coloar *removido = p->dados[--p->topo]; - diminui primeiro porque ele ta avançado
    *removido = p->dados[p->topo]; //conteudo que removido aponta recebe
    return 1;
}

void exibe_pilha (t_pilha_caracter *p){
    if(pilha_vazia(p)) printf("A pilha esta vazia\n\n");
    else {
        for(int i = p->topo-1;i>=0; i--){
            printf("%c\n", p->dados[i]);
        }
    }
    printf("--------------\n");
}

void inverte_pilha(t_pilha_caracter *p){
    t_pilha_caracter *invertida;
    invertida = (t_pilha_caracter *) malloc (sizeof(t_pilha_caracter));
    constroi_pilha(p->capacidade, invertida);
    char aux;
    while (pop(p, &aux)){
        push(aux, invertida); //só passa o ponteiro - não &invertida
    }
    exibe_pilha(invertida);
    p->dados = invertida->dados; //mudou o topo da invertida e não da original
    p->topo = invertida->topo;
}