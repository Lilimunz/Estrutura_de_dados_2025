#include <stdio.h>

void f1(const int a){
    //a++;
}

int main () {
    int x = 10;
    f1(x);
    printf("Digite dois inteiro: ");
    int i, j, k;
    j = scanf("%d%d", &i, &k); //scanf recebe a referencia da variavel
    printf("i = %d\nk = %d\nj = %d\n", i, k, j); //tokens de leitura j
    return 0;
}