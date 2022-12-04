#include <iostream>
#include "NOfila.hpp"
#include "pilhaNO.hpp"
#include <cctype>

using namespace std;


int main(){
    string frase;
    Fila* fila = new Fila();
    Stack* p = new Stack();
    cout << "Frase: " << endl;
    cin >> frase;

    for (int i = 0; i < frase.length(); i++)
    {
        if (isalpha(frase[i]))
        {
            fila->enfileira(toupper(frase[i]));
            p->empilha(toupper(frase[i]));

        }
        
    }

    do
    {
        if (fila->emptyQueue())
        {
            cout << "É palindroma" << endl;
        }else{
            cout << "Não é palindroma.";
        }
        
    } while (fila->emptyQueue() == false && fila->desenfileira() == p->desempilha());
    
    return 0;
}