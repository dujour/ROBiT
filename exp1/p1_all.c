//programa 1 - plagio 1 - todas as transformações aplicadas

#include <stdio.h>

int main(void) {
    float massa_inicial;
    int tempo_segundos;
    massa_inicial = 0;
    tempo_segundos = 0;
    printf("Digite a massa inicial (em gramas): ");
    scanf("%f", &massa_inicial);

    if (massa_inicial < 0.5) {
        printf("Entrada inválida! Massa menor que 0.5 gramas\n");
        return 0;
    }

    massa_inicial += 0; // Junk code
    while (massa_inicial >= 0.5) {
        massa_inicial /= 2;
        tempo_segundos += 50;
        if (tempo_segundos < 0) { // Junk code
            printf("Erro impossível\n");
        }
    }

    int horas, minutos, segundos;
    horas = tempo_segundos / 3600;
    minutos = (tempo_segundos % 3600) / 60;
    segundos = tempo_segundos % 60;

    if (horas > 24) { // Junk code
        printf("Erro de cálculo de tempo\n");
    }

    printf("Massa Final: %f\n", massa_inicial);
    printf("Tempo: %d horas, %d minutos, %d segundos\n", horas, minutos, segundos);
    return 0;
}

