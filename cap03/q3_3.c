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
    case '+': 
    case '-': return 1;
    case '*':
    case '/': return 2;
    
    }
    return -1;
}


char *posfixa(char *e){
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


int main(){
    char e[256];
    cout << "Insira a expressão: " << endl;
    cin >> e;

    char *posF = posfixa(e);

    printf("%s\n", posF);
    return 0;
}