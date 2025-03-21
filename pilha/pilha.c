#include "pilha.h"

void constroi_pilha (int capacidade, t_pilha *p) {
    p->dados = (int *) malloc (capacidade * sizeof(int));
    p->topo = 0;
    p->capacidade = capacidade;
}

int pilha_vazia (t_pilha *p){
    if(p->topo == 0) return 1;
    return 0; //pode colocar else ou não
    // return p-topo == 0; - joga o teste pro compilador
    //return !p->topo; - negação pq na pilha ta verdadeiro
}

int pilha_cheia (t_pilha *p){
    if(p->topo == p->capacidade) return 1;
    return 0;
    //return p->topo == p->capacidade; - ele faz o teste e devolve
}

int push (int i, t_pilha *p) {
    if (pilha_cheia(p)) return 0;
        p->dados[p->topo] = i; //pode incrementar depois com p->dados[p->topo++] = i mas tem que apagar a linha de p->topo++;
        p->topo++; // como se tivesse com (p->topo)++ porque seta tem preferencia que incremento
        return 1;
}

int pop (t_pilha *p, int *removido) {
    if(pilha_vazia(p)) return 0; //limoa o caminho o que sobrou vai liso
    p->topo--; //tem como coloar *removido = p->dados[--p->topo];
    *removido = p->dados[p->topo]; //conteudo que removido aponta recebe
    return 1;
}

void exibe_pilha (t_pilha *p){

}

int main () {

    return 0;
}