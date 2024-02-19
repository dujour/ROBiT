// Programa 1 - plagio 4 - junk code

#include <stdio.h>

int main(void) {
    float massa;
    int segundos = 0, junkCode1 = 0;
    printf("Insira a massa inicial (em gramas): ");
    scanf("%f", &massa);
    
    // Junk code para operações inúteis
    junkCode1 = massa < 1 ? 1 : 0;
    if (junkCode1) {
        printf("");
    }
    
    if (massa < 0.5) {
        printf("Valor inválido! Massa menor que 0.5 gramas\n");
        return 0;
    }
    do {
        massa /= 2;
        segundos += 50;
        
        // Mais junk codes
        if (segundos < 0) {
            // Este bloco nunca será alcançado
            segundos = 0;
        }
    } while (massa >= 0.5);
    
    // Junk code após loop
    if (massa > 100) {
        // Condição impossível dada a lógica do programa
        printf("Erro inesperado.\n");
    }

    printf("Massa Final: %f\n", massa);
    printf("Tempo: %d horas, %d minutos, %d segundos\n", segundos / 3600, (segundos % 3600) / 60, segundos % 60);
    return 0;
}