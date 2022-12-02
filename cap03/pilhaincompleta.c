#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class No {
	public:
		char nome;
		No *prox;

		No(char n) {
			nome = n;
			prox = NULL;
		}
};

class Pilha{ 
	public:
		No* topo;
		
		Pilha() {
			topo = NULL;
		}
		
		void push(char n) {
			No* novoNo = new No(n);
			if(isEmpty()) {
				topo = novoNo;
			} else {
				novoNo->prox = topo;
				topo = novoNo;
			}
		}
		
		char pop() {
			if(isEmpty()) {
				return '\0';
			} else {
				No* aux = topo;
				topo = topo->prox;
				char valor = aux->nome;
				free(aux);
				return valor;
			}
		}
		
		int isEmpty() {
			return topo == NULL;
		}

		void destroy() {
			while(!isEmpty()) {
				pop();
			}
		}
	
	
};

int main() {
	
	Pilha* pilha_teste  = new Pilha;

	cout << "pilha criada" << endl;

    cout << "pilha vazia ?: " << pilha_teste->isEmpty() << endl;

    cout << "inserir 5 valores: ";

    for(int i = 0; i < 5; i++) {
        char valor;
        cin >> valor;
        pilha_teste->push(valor);
    }

    cout << "pop: " << pilha_teste->pop() << endl;
	cout << "pop: " << pilha_teste->pop() << endl;

    cout << "pilha vazia ?: " << pilha_teste->isEmpty() << endl;

    cout << "esvaziar pilha" << endl;
    
    pilha_teste->destroy();

    cout << "pilha vazia ?: " << pilha_teste->isEmpty() << endl;

    return 0;

	
}