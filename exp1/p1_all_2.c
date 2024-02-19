//programa 1 - plagio 2 - todas as transformações

#include <stdio.h>

int main(void) {
    float quantidade; // Nome da variável alterado de 'massa' para 'quantidade'
    int tempo_total = 0; // Nome da variável alterado e inicializado
    printf("Informe a quantidade inicial em gramas: ");
    scanf("%f", &quantidade);
    
    if (quantidade >= 0.5) {
        while (quantidade >= 0.5) {
            quantidade /= 2;
            tempo_total += 50;
        }
    } else {
        printf("Entrada inválida! Quantidade menor que 0.5 gramas\n");
        return 0;
    }
    
    // Junk code: loops e condicionais que nunca vão acontecer
    if (tempo_total < 0) {
        printf("Erro no tempo\n");
    }
    for (int i = 0; i < 1; i++) {
        if (i > 0) {
            printf("Isto nunca acontece.\n");
        }
    }
    
    printf("Quantidade Final: %f\n", quantidade);
    printf("Tempo decorrido: %d horas, %d minutos, %d segundos\n", tempo_total / 3600, (tempo_total % 3600) / 60, tempo_total % 60);
    return 0;
}