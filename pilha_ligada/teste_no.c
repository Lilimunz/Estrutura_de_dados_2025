#include "no.h"

int main () {
    t_no no1;
    t_no *p_no;

    no1.info = 3;
    no1.prox = NULL;
    //printf ("p_no = %p\n", p_no);
    //p_no->info = 5;

    p_no = constroi_no(5);
    printf("conteudo do no apontado por p_no: %d\n", p_no->info);
    no1.prox = p_no;
    p_no = &no1;
    p_no->info = 12;
    no1.prox->info = 20;
}
