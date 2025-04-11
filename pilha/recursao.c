#include <stdio.h>

//vamos estourar o int depois vamos usar a recursao
double fat_it (int n){ //com laço - para verificar limite do inteiro
    double f = 1;
    // for (int i=2; i <=n; i++){
    //     f = f *i;
    // }
    while (n>1){
        f = f * n--; //multiplica e baixa ele - utiliza o n de limite
    }
    return f;
}

long fat_rec(int n){
    if ( n <=1) return 1;
    return n * fat_rec(n-1);
}

long fibonacci (int n){
    if (n <=1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

void exibe_1_a_n_rec1(int i, int n){
    printf("%d ", i);// exibe o 1
    if(i < n) exibe_1_a_n_rec1(i+1, n); //chama pro 2
    
}

void exibe_1_a_n_rec2(int i, int n){
    if(i < n) exibe_1_a_n_rec2(i+1, n); //chama pro 2
    printf("%d ", i);// exibe o 1
    
}

void exibe_1_a_n_rec3(int n){
    printf("%d ", n);
    if (n > 1) exibe_1_a_n_rec3(n-1); 
}

void exibe_1_a_n_rec4(int n){
    if (n > 1) exibe_1_a_n_rec4(n-1); 
    printf("%d ", n);
}

int main(){
    for(int i=0; i<=20; i++){//!13 - 6227020800 * 14 = 871782'91200'(esse eh o certo) no float - 871782'89152' - diferença entre eles é 2048 - 10¹¹
        printf("fatorial %d: %.0lf\n", i, fat_it(i));
    }
    printf("\n");

    for(int i=0; i<=13; i++){
        printf("fatorial recursivo %d: %.0ld\n", i, fat_rec(i));
    }
    printf("\n");

    for(int i=0; i<=13; i++){
        printf("fibonacci em %d: %.0ld\n", i, fibonacci(i));
    }
    printf("\n");

    exibe_1_a_n_rec1 (1, 5); //onde estou até onde vou
    printf("\n");
    exibe_1_a_n_rec2 (1, 5);
    printf("\n");
    exibe_1_a_n_rec3 (5);
    printf("\n");
    exibe_1_a_n_rec4 (5); // empilha primeiro - vem pra ordem correta
    return 0;
}