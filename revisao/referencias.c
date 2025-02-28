#include <stdio.h>

int main () {
    int a = 100;
    printf("\nvalor de a (decimal) = %d\n", a);
    printf("valor de a (hexadecimal): %x\n", a);
    printf("endereco de a = %p\n",&a);
    printf("caracter equivalente de a: %c\n", a); //tabela ascii
    //printf("string de a: %s\n", a); //erro de acesso à memoria no endereço
    printf("string da referencia de a: %s\n", &a); //operador referencia

    return 0;
}