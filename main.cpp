#include <stdio.h>

/*
Proposta: 
   Leia o valor do dólar e um valor em dólar, calcule e escreva o equivalente em real (R$).
*/

int main() {
    float dolar, valor_dolar, real;

    printf("Valor do dolar: ");
    scanf("%f", &valor_dolar);

    printf("Valor em dolar a ser convertido em real: ");
    scanf("%f", &dolar);

    real = dolar * valor_dolar;

    printf("\n$%.2f = R$%.2f", dolar, real);
    
    return 0;
}