#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i;
    float x, term, arctanx = 0;

    printf("Entre com o valor de x para calcular arctan(x) (-1<x<1): ");
    scanf("%f", &x);
    if (-1 < x && x < 1) {
        printf("Entre com o numero de termos: ");
        scanf("%d", &n);
        i = 0; // Alteração iniciada aqui
        while (i < n) { // Mudança do for para while para manter a semântica mas alterar a estrutura
            term = pow(-1, i) * pow(x, 2*i+1) / (2*i+1);
            arctanx += term;
            i++; // Incremento de i dentro do loop while
        } // Fim da alteração
        printf("Angulo em radianos = %f\n", arctanx);
        printf("Angulo em graus = %f\n", (arctanx * 180) / M_PI);
    } else {
        printf("Valor invalido!\n");
    }
    return 0;
}