#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "../ferramentas/pilha1.h"



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
        }else if(isdigit(e[i])){
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


float value(char *e){
    Pilha p = pilha(256);
    for (int i = 0; e[i]; i++)
    {
        if (isdigit(e[i]))
        {
            empilha(atof(e[i+1]), p);
            while (isdigit(e[i+1]) || e[i+1] =='.')
            {
                i++;
            }
            
        }else if(strchr("+*-/", e[i])){
            float y = desempilha(p);
            float x = desempilha(p);
            switch (e[i])
            {
            case '+': empilha(x+y,p); break;
            case '-': empilha(x-y,p); break;
            case '*': empilha(x*y,p); break;
            case '/': empilha(x/y,p); break;
            }
            
        
        }
        
    }
    double z = desempilha(p);
    // destroiP(&p);
    return z;
    
}


int main(){
    char e[256];
    printf("Insira a expressão: \n");
    scanf("%s", &e);

    char *posF = posfixa(e);
    int v = value(posF);

    printf("%s\n", posF);
    printf("%d",v);
    return 0;
}