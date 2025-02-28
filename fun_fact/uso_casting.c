#include <stdio.h>

int main () {

    int a;
    float x = 5.75;
    
    a = (int) x; //a recebe a parte inteira do que está em x
    printf("\na = %d\n", a);

    x = a;
    printf("x = %.0f\n", x);

    int m = 17, n = 3;
    float p = m / n;
    printf("divisao = %.0f\n", p);

    float y = (float) m / (float) n; //casting - basta um, mas também pode ser os dois
    //vale apenas para variaveis, não literais. 
    printf("outra divisao: %.2f\n", y);

    //ler um valor float e exibir somente a parte decimal
    float decimal = y - (int)y; //  5.67 - 5  = 0.667
    printf("decimal = %.3f\n", decimal);

    return 0;
}