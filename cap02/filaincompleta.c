#include <iostream>
 
using namespace std;
 
class No {
 
	public:
 
		char valor;
		No* prox;
 
		No(char n){
			valor = n;
			prox = NULL;
		}
};
 
class Fila {
 
	public:
 
		No* inicio;
		No* fim;
 
		Fila() {
			inicio = NULL;
			fim = NULL;
		}
 
		void append(char n) {
			if(isEmpty()) {
                inicio = new No(n);
                fim = inicio;
			} else {
                No* novoNo = new No(n);
                fim->prox = novoNo;
                fim = novoNo;
			}
		}
 
		char pop() {
			if(!isEmpty()) {
                char valor = inicio->valor;
                No* aux = inicio;
                inicio = inicio->prox;
                free(aux);
                return valor;
			} else return '\0';
		}
 
		bool isEmpty() {
			return (inicio == NULL);
		}
 
		void popAll() {
			while(!isEmpty()) {
				pop();
			}
		}
};
 
int main() {

    Fila* fila_teste  = new Fila;

    cout << "fila vazia ?: " << fila_teste->isEmpty() << endl;

    cout << "inserir 5 valores: ";

    for(int i = 0; i < 5; i++) {
        char valor;
        cin >> valor;
        fila_teste->append(valor);
    }

    cout << "pop :" << fila_teste->pop() << endl;
    cout << "pop :" << fila_teste->pop() << endl;

    cout << "fila vazia ?: " << fila_teste->isEmpty() << endl;

    cout << "popAll" << endl;
    
    fila_teste->popAll();

    cout << "fila vazia ?: " << fila_teste->isEmpty() << endl;

    return 0;
 
}
