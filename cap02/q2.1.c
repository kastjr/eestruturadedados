#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
#include "../Pilha/pilha1.h"


//Sa�da: n possui um tipo de argumento un�rio inv�lido

int main(void){
    Pilha p = pilha(3);
    empilha(1,p);
    empilha(2,p);
    printf("%d\n", desempilha(p));
    printf("%d\n", desempilha(p));
    printf("%d\n", desempilha(p));
    return 0;
}

