#include <stdio.h>
#include <math.h>
int main(void){
    int n_termos;
    int contador = 0; // Definição separada
    int sinal;
    sinal = 1; // Definição separada
    int expoente = 1; // Inicialização separada
    float arctanx = 0; // Inicialização separada
    float x;
    int junk1 = 0; // Junk code
    junk1++; // Junk code

    printf("Entre com o valor de x para calcular arctan(x): ");
    scanf("%f", &x);

    if(-1 < x && x < 1){
        printf("Entre com o numero de termos: ");
        scanf("%d", &n_termos);
        while(contador < n_termos){
            expoente = (2 * contador) + 1;
            arctanx += sinal * (pow(x, expoente) / expoente);
            sinal *= -1;
            contador++; // Movido para dentro do loop
            int junk2 = 1; // Junk code
            junk2--; // Junk code
        }
        printf("Angulo em radianos = %f", arctanx);
        printf("\nAngulo em graus = %f", (arctanx * 180) / M_PI);
    } else {
        printf("Valor invalido!");
    }

    return 0;
}
