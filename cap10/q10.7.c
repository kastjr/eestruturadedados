#include <stdlib.h>
#include <stdio.h>

typedef struct poli {
    float coef;
    int expo;
    struct poli* prox;    
}* Poli;

Poli termo(float c, int e, Poli P) {
    Poli novo_termo = (Poli) malloc(sizeof(Poli));

    novo_termo->coef = c;
    novo_termo->expo = e;
    novo_termo->prox = P;

    return novo_termo;
}

void adt(float c, int e, Poli* P) {
    if(*P == NULL || (*P)->expo < e) {
        *P = termo(c, e, *P);
    } else if((*P)->expo == e) {
        (*P)->coef += c;
        if((*P)->coef == 0) {
            Poli n = *P;
            *P = n->prox;
            free(n);
        }
    } else {
        adt(c, e, &(*P)->prox);
    }
}

Poli soma(Poli p1, Poli p2) {
    Poli resultado;
    while(p1 != NULL) {
        adt(p1->coef, p1->expo, &resultado);
        p1 = p1->prox;
    }

    while(p2 != NULL) {
        adt(p2->coef, p2->expo, &resultado);
        p2 = p2->prox;
    }

    return resultado;
}

int main() {
    Poli c1 = termo(7, 1, NULL);
    Poli b1 = termo(3, 2, c1);
    Poli p1 = termo(2, 3, b1);

    Poli c2 = termo(7, 2, NULL);
    Poli b2 = termo(3, 3, c2);
    Poli p2 = termo(2, 4, b2);

    Poli resultado = soma(p1, p2);

    while(resultado != NULL) {
        if(resultado->prox == NULL) {
            printf("%.0fx^%d\n", resultado->coef, resultado->expo);
        } else {
            printf("%.0fx^%d + ", resultado->coef, resultado->expo);
        }
        resultado = resultado->prox;
    }

    return 0;
}