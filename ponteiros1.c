#include <stdio.h>

int main () {
    //int v[100]; testes de alocação com varios tamanhos

    int a = 23;
    //int *p = 6789; //ponteiro de inteiro - mas não é usual atribuir um "valor" mesmo para um ponteiro
    int * p = &a;
    int **x = &p;
    printf("a = %d\np = %p\nx = %p\n", a, p,x);

    *p = 67;
    
    int *j;
    int **k;
    int b = 10;
    k = &j;
    j = &b;

    *k = &a; //desreferenciar - operação pela qual um programador acessa o valor armazenado no endereço de memória apontado por um ponteiro

    printf("foi");
    return 0;
}