#include <stdio.h>
#include <math.h>
int main(void){
    int n_termos;
    float arctanx = 0.0, x;
    int opcao;

    printf("Entre com o valor de x para calcular arctan(x): ");
    scanf("%f", &x);

    if (-1 < x && x < 1) {
        printf("Entre com o numero de termos: ");
        scanf("%d", &n_termos);
        
        for (int contador = 0; contador < n_termos; contador++) {
            int expoente = (2 * contador) + 1;
            arctanx += pow(-1, contador) * (pow(x, expoente) / expoente);
        }
        
        printf("Selecione a opção de saída (1 para radianos, 2 para graus): ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Angulo em radianos = %f", arctanx);
        } else if (opcao == 2) {
            printf("Angulo em graus = %f", (arctanx * 180) / M_PI);
        } else {
            printf("Opção inválida. Exibindo ambos.\n");
            printf("Angulo em radianos = %f\n", arctanx);
            printf("Angulo em graus = %f", (arctanx * 180) / M_PI);
        }
    } else {
        printf("Valor invalido!");
    }

    return 0;
}
