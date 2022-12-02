#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "../Pilha/pilha1.h"
#include <string>
#include <cstring>

using namespace std;




int main(){
    
    // string a = "apenas um teste";
    char texto[150];

    printf("Insira uma frase: ");
    scanf("%[^\n]", &texto);


    // cout << a << endl;
    Pilha p = pilha(strlen(texto));
    

    for (int i = 0; i < strlen(texto)+1; i++)
    {
        if(texto[i] != ' ' && texto[i] != '\0'){
            empilha(texto[i], p);

        }else{
            while (!pilhaVazia(p))
            {
                cout << desempilha(p);
                
            }
            cout << " ";

        }
        
            
    }
    cout << endl;
    system("pause");




}








    // for (int c = 0; c < a.length(); c++)
    // {

    // }
    
    
    // // scanf("%s", a);
    // // printf("%s", a);
    // return 0;