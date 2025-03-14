#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declaração das funções, ie, seus protótipos
void preenche_vetor(int[], int);
void preenche_sem_repetir(int[], int);
void exibe_vetor(int[], int, char *);
void bubble_sort(int[], int);
int busca_simples(int, int[], int);
int busca_e_conta(int, int[], int); // retorna o número de vezes que x aparece no vetor
int busca_binaria(int, int[], int);

int main()
{
    int *v;
    int n;
    srand(time(0));
    printf("escolha o tamanho do vetor, 0 encerra: ");
    scanf("%d", &n);
    while (n > 0){
        v = (int *)malloc(n * sizeof(int));
            preenche_vetor(v, n);//subrotina
          //exibe_vetor(v, n, "vetor original");
            int x;
            printf("\nDigite o valor para a busca: ");
            scanf("%d", &x);
            if (busca_simples(x, v, n)){ //assim ou com == 1
                printf("\n%d esta no vetor\n", x);
            }
            else {
                printf("\n%d nao esta no vetor\n", x);
            }

        //     int result = busca_e_conta(x, v, n); //quando utilizar mais de uma vez, guarda em uma variavel
        //     if (result == 0){
        //         printf("\n%d nao aparece no vetor\n", x);
        //     }
        //     else if (result == 1){
        //         printf("\n%d aparece uma unica vez\n", x);
        //     }
        //     else {
        //         printf("\n%d aparece %d vezes\n", x, result);
        //     }
        // preenche_sem_repetir(v, n);
        // long int ini = time(0);
        bubble_sort(v, n);
        int pos = busca_binaria(x, v, n);
        exibe_vetor(v, n, "vetor oredenado");
        if ( pos == -1){
            printf("busca binaria nao encontrou %d\n", x);
        }
        else {
            printf("busca binaria encontrou %d, na posicao %d", x, pos);
        }
        // long int fim = time(0);
        // exibe_vetor(v, n, "vetor ordenado");
        // printf ("\ntempo de ordenacao: %ld\n", fim-ini);
        // preenche_sem_repetir(v, n);
        // bubble_sort(v, n);
        // exibe_vetor(v, n, "vetor sem repeticao");
        free(v);
        printf("\nescolha o novo tamanho, 0 encerra: ");
        scanf("%d", &n);
    }
    // while (1) {
    //     v = (int *) malloc (4000000);
    //     printf ("endereco alocado: %p\n", v);
    //     free(v);
    // }
    return 0;
}

void preenche_vetor(int v[], int n)
{
    for (int i = 0; i < n; i++){
        v[i] = rand() % (10 * n); // para forçar a repetição coloca % (n)
    }
}

void exibe_vetor(int v[], int n, char *msg)
{
    printf("\n%s\n", msg);
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void bubble_sort(int v[], int n)
{
    for (int i = 1; i < n; i++){
        for (int j = 0; j < n - i; j++){
            if (v[j] > v[j + 1]){
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

int busca_simples(int x, int v[], int n)
{
    for (int i = 0; i < n; i++){
        if (v[i] == x){
            return 1;
        }
    }
    return 0;
}

int busca_e_conta(int x, int v[], int n)
{
    int cont = 0;
    for (int i = 0; i < n; i++){
        if (v[i] == x){
            cont++;
        }
    }
    return cont;
}

void preenche_sem_repetir(int v[], int n)
{
    v[0] = rand() % (n);
    printf("%d ", v[0]);
    for (int i = 1; i < n; i++){
        int r = rand() % n;
        while (busca_simples(r, v, i)){
            r = rand() % n;
        }
        v[i] = r;
        printf("%d ", v[i]);
    }
}

int busca_binaria(int x, int v[], int n)
{
    int inicio = 0, fim = n - 1;
    while (inicio <= fim){
        int meio = (inicio + fim) / 2;
        if (x == v[meio]){
            return meio;
        }
        if (x > v[meio]){
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }
    return -1;
}