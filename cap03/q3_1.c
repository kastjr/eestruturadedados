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

int value(char *e){
    Pilha p = pilha(256);
    for (int i = 0; e[i]; i++)
    {
        if (isdigit(e[i]))
        {
            empilha(e[i] - '0',  p);
        
            
        }else{
            int y = desempilha(p);
            int x = desempilha(p);
            switch (e[i])
            {
            case '+': empilha(x+y,p); break;
            case '-': empilha(x-y,p); break;
            case '*': empilha(x*y,p); break;
            case '/': empilha(x/y,p); break;
            }
            
        
        }
        
    }
    int z = desempilha(p);
    // destroiP(&p);
    return z;
    
}






char *posfixa(char *e){
    static char s[256];
    Pilha p = pilha(256);
    int j = 0 ;
    for (int i = 0; e[i]; i++)
    
        if (e[i]=='(')
        {
            empilha(e[i], p);
        }else if(isdigit(e[i])){
            s[j++] = e[i];
        }else if (strchr("+-/*", e[i]))
        {
            while (!pilhaVazia(p) && (prio(top(p)) >= prio(e[i])))
            {
                s[j++] = desempilha(p);
            }
            empilha(e[i], p);
            
        }else if (e[i] == ')')
        {
            while (top(p) != '('){
                s[j++] = desempilha(p);

            }
            desempilha(p);
        }
                 
    
    while (!pilhaVazia(p)){
        s[j++] = desempilha(p);
    } 
    s[j] = '\0';
    // destroiP(&p);
    return s;
}




int main(){
    char e[256];
    printf("Infixa?\n");
    scanf("%s", &e);

    char *posF = posfixa(e);
    int v = value(posF);

    printf("%s\n", posF);
    printf("%d",v);
    return 0;
}