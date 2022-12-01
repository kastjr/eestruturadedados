#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include "../ferramentas/pilha1.h"


using namespace std;


int prio(char a){
    switch (a)
    {
    case '(': return 0;
    case '|': return 1;
    case '&': return 2;
    case '~': return 3;
    
    }
    return -1;
}


char* posfixa(char *e){
    static char s[256];
    Pilha p = pilha(256);
    int j = 0 ;
    for (int i = 0; e[i]; i++)
    
        if (e[i]=='(')
        {
            empilha('(', p);
        }else if(isalpha(e[i])){
            s[j++] = e[i];
        }else if (strchr("+-/*", e[i]))
        {
            while (!pilhaVazia(p) && prio(top(p)) >= prio(e[i]))
            {
                s[j++] = desempilha(p);
            }
            empilha(e[i], p);
            
        }else if (e[i] == ')')
        {
            while (top(p) != '(')
            
                s[j++] = desempilha(p);
                desempilha(p);
            
            
            s[j++] = desempilha(p);
            desempilha(p);
        }
                 
    
    while (!pilhaVazia(p)) s[j++] = desempilha(p);
    s[j] = '\0';
    destroiP(&p);
    return s;
}


char Not(char p){
    if(p == 'V')return 'F';
    return 'V';
}

char And(char p, char c){
    if(p == 'F')return 'F';
    if(c == 'F')return 'F';
    return 'V';
}

char Or(char p, char c){
    if(p == 'V')return 'V';
    if(c == 'V')return 'V';
    return 'F';
}




char value(char* e){
 Pilha p = pilha(e);
 for (int i = 0; e[i]; i++) {
    if(strchr("VF", e[i])) empilha(e[i], p);
    else{
        int a = desempilha(p);
        int b;
        switch (e[i]){
            case '~': empilha(Not(a), p); break;
            case '&': b = desempilha(p); empilha(And(a, b), p); break;
            case '|': b = desempilha(p); empilha(Or(a, b), p); break;
            
        
            }
        }
    }
    char z =desempilha(p);
    destroiP(p);
    return z;
}



int main(){
    char e[256];
    cout << "Insira a expressão: " << endl;
    cin >> e;

    char *posF = posfixa(e);
    int v = value(posF);
    cout << posF << endl;
    cout << v << endl;


    return 0;
}