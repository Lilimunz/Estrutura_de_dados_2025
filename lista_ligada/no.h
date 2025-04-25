#include <stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
}t_no;

t_no * constroi_no (int);
