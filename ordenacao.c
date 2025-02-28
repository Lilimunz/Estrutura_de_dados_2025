#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaração das funções, ie, seus protótipos
    void preenche_vetor(int[], int);
    void exibe_vetor(int[], int);

int main () {
    int *v;
    int n;
    srand(time(0));

    printf("Digite um tamanho para o vetor: ");
    scanf("%d", &n);

    v = (int *) malloc (n * sizeof(int));
    
    preenche_vetor(v, n); //subrotina
    exibe_vetor(v, n);

    return 0;
}
void preenche_vetor(int v[] , int n){
    for(int i=0; i<n;i++){
        v[i] = rand();
    }
}


void exibe_vetor(int v[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}