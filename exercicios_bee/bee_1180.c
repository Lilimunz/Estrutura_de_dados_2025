#include <stdio.h>
#include <stdlib.h>
int main () {
    int n, *x; 
    scanf("%d", &n);
    x = (int *) malloc (n * sizeof(int)); 
    // scanf("%d", &x[0]); // inicializar separadamente a posição 0 fora do laço para 
    // int m = x[0];
    // int pos=0;
    // for (int i=1; i<x; i++) {
    //     if(x[i] < m){
    //         m = x[i];
    //         pos = i;
    //     }
    // }

    for (int i=0; i<n; i++) {
        scanf("%d", &x[i]);
    }
    int m = x[0];
    int pos = 0;
    for(int i=1; i<n; i++) {
        if(x[i] < m){
            m = x[i];
            pos = i;
        }
    }
    printf("Menor valor: %d\n", m);
    printf("Posicao: %d\n", pos);
    printf("\n");
    return 0;
}