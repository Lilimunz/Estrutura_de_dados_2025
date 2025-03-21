#include <stdio.h>

// ler uma sequencia de numeros, até encontrar EOF, soma-los e exibir a soma
int main () {
    int a, b, n;
    while (scanf("%d", &a) != EOF){
        printf("%d ", a);
    }
    printf("\nacabou o arquivo");
    // printf("Digite dois numeros: ");
    // n = scanf("%d%d", &a, &b);
    // printf("\nn = %d\n", n);

    return 0;
}