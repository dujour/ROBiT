#include <stdio.h>
#include <math.h>
int main(void){
    int n_termos = 0; // Inicialização explícita
    int contador = 0; // Inicialização explícita
    int sinal = 1; // Inicialização explícita
    int expoente = 1; // Inicialização explícita
    float arctanx = 0.0; // Explicitação do valor
    float x;
    int opcao = 0; // Para uso com switch-case
    int junkVar1 = 0; // Junk code

    printf("Entre com o valor de x para calcular arctan(x): ");
    scanf("%f", &x);

    if(-1 < x && x < 1){
        printf("Entre com o numero de termos: ");
        scanf("%d", &n_termos);
        
        contador = 0; // Reset contador para garantir
        do {
            expoente = (2 * contador) + 1;
            arctanx += sinal * (pow(x, expoente) / expoente);
            sinal *= -1;
            contador++;
            junkVar1++; // Junk code
        } while(contador < n_termos);
        
        printf("Selecione a opção de saída (1 para radianos, 2 para graus): ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("Angulo em radianos = %f", arctanx);
                break;
            case 2:
                printf("Angulo em graus = %f", (arctanx * 180) / M_PI);
                break;
            default:
                printf("Opção inválida. Exibindo ambos.\n");
                printf("Angulo em radianos = %f\n", arctanx);
                printf("Angulo em graus = %f", (arctanx * 180) / M_PI);
                int junkVar2 = 5; // Junk code
                junkVar2 -= 5; // Junk code
        }
    } else {
        printf("Valor invalido!");
        float junkVar3 = 3.14; // Junk code
        junkVar3 *= 0; // Junk code
    }

    // Junk code no final do programa
    int finalJunk = 100; // Junk code
    finalJunk = 0; // Resetting junk variable

    return 0;
}