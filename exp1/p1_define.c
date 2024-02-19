//programa 1 - plagio 4 - transformações de define

#include <stdio.h>

int main(void) {
    float valorMassa;
    int contagemTempo;
    valorMassa = 0.0;
    contagemTempo = 0;
    printf("Insira a massa inicial (em gramas): ");
    scanf("%f", &valorMassa);
    if (valorMassa < 0.5) {
        printf("Valor inválido! Massa menor que 0.5 gramas\n");
        return 0;
    }
    do {
        valorMassa /= 2;
        contagemTempo += 50;
    } while (valorMassa >= 0.5);

    int h, m, s;
    h = contagemTempo / 3600;
    m = (contagemTempo % 3600) / 60;
    s = contagemTempo % 60;
    printf("Massa Final: %f\n", valorMassa);
    printf("Tempo: %d horas, %d minutos, %d segundos\n", h, m, s);
    return 0;
}
