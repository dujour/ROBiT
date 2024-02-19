//programa 1 - original


#include <stdio.h>

int main(void) {
    float massa;
    int segundos = 0;
    printf("Insira a massa inicial (em gramas): ");
    scanf("%f", &massa);
    if (massa < 0.5) {
        printf("Valor inválido! Massa menor que 0.5 gramas\n");
        return 0;
    }
    do {
        massa /= 2;
        segundos += 50;
    } while (massa >= 0.5);

    printf("Massa Final: %f\n", massa);
    printf("Tempo: %d horas, %d minutos, %d segundos\n", segundos / 3600, (segundos % 3600) / 60, segundos % 60);
    return 0;
}
