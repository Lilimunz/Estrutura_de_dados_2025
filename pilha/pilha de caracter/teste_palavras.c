#include <string.h>
#include "pilha_caracter.h"

int main () {
    char palavra[20];
    t_pilha_caracter pc;
    printf("Digite uma palavra: ");
    scanf("%s", palavra); //todo vetor é um ponteiro, sem &!!!
    constroi_pilha (strlen(palavra), &pc);
    for (int i = 0; i < strlen(palavra); i++){
        push(palavra[i], &pc);
    }
    int e_palindromo = 1; //todos são iguais até achar o diferente
    int i =0;
    char aux;

    while(!pilha_vazia(&pc) && e_palindromo){
        pop(&pc, aux);
        if (palavra[i] != aux){
            e_palindromo = 0;
        }
        else{
            i++;
        }
    }
    if(e_palindromo){
        printf("%s eh palindromo\n", palavra);
    }
    else {
        printf("%s nao eh palindromo\n", palavra);
    }

    return 0;
}