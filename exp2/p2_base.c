#include <stdio.h>
#include <math.h>
int main(void){
int n_termos, contador;
int sinal=1;
int expoente=1;
float arctanx=0;
float x;

printf ("Entre com o valor de x para calcular arctan(x): ");
scanf ("%f", &x);


    if(-1<x && x<1){
        printf ("Entre com o numero de termos: ");
        scanf ("%d", &n_termos);
        for(contador=0; contador<n_termos; contador++){
        expoente = (2 * contador ) + 1 ;
        arctanx += sinal * (pow(x, expoente)/expoente);
        sinal *=-1;
        ;
                                                       }
            printf ("Angulo em radianos = %f", arctanx);
            printf ("\nAngulo em graus = %f", (arctanx*180)/M_PI);
             }

    else(
         printf("Valor invalido!"));


return 0;
}