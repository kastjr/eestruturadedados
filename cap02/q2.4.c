#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <iostream>
#include "../Pilha/pilha1.h"

using namespace std;


int ordenar_Pilhas(Pilha pilhaA, Pilha pilhaB){
    Item item;
    Item anterior;

    for (int i = 0; i < pilhaA->max; i++)
    {
        cout << " item" << i << ": " << endl;
        cin >> item;   

        anterior = (i==0) ? item : pilhaA -> item[pilhaA->topo];


        while (item<anterior){
            empilha(desempilha(pilhaA), pilhaB);
            anterior = pilhaA->item[pilhaA->topo];
        }
    
    }
    
    if(item >= anterior){
        empilha(item, pilhaA);
    }
    while (!pilhaVazia(pilhaB)){
        item = desempilha(pilhaB);
        empilha(item, pilhaA);
    }
   
    return 0;
}


int main(){
    int tamanho;
    cout << "Qtd itens: " << endl;
    cin >> tamanho;

    Pilha pA = pilha(tamanho);
    Pilha pB = pilha(tamanho);

    ordenar_Pilhas(pA, pB);

    cout << "Pilhas orndenadas: " << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cout << desempilha(pA) << endl;
    }
    return 0;
}