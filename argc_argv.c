// argc = argument counter
// argv = argument vector/value

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
    int i, soma;

    // for (i=0; i<argc; i++){
    //     printf("argumento %d: %s\n", i, argv[i]);
    // }
    for(i=1, soma=0; i<argc; i++){
        soma = soma + atoi(argv[i]);
    }
    i = printf("%d\n", soma);
    printf("for your knowlegde: i = %d\n", i); // +1 enter
    return 0;
}