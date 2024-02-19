#include <stdio.h>
#include <math.h>

int main(void) {
    int n_termos;
    float arctanx, x;
    int opcao;

    arctanx = 0.0; // Inicialização separada

    printf("Entre com o valor de x para calcular arctan(x): ");
    scanf("%f", &x);

    if (-1 < x && x < 1) {
        printf("Entre com o numero de termos: ");
        scanf("%d", &n_termos);

        for (int contador = 0; contador < n_termos; contador++) {
            int expoente;
            expoente = 2 * contador + 1; // Definição separada
            float termo;
            termo = pow(-1, contador) * (pow(x, expoente) / expoente); // Cálculo do termo separado
            arctanx += termo;
        }

        printf("Selecione a opção de saída (1 para radianos, 2 para graus): ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Angulo em radianos = %f", arctanx);
        } else if (opcao == 2) {
            float graus;
            graus = arctanx * (180 / M_PI); // Conversão e definição separadas
            printf("Angulo em graus = %f", graus);
        } else {
            printf("Opção inválida. Exibindo ambos.\n");
            printf("Angulo em radianos = %f\n", arctanx);
            printf("Angulo em graus = %f", arctanx * (180 / M_PI));
        }
    } else {
        printf("Valor invalido!");
    }

    return 0;
}