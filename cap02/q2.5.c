#include "pilhaChar.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"

bool is_valid(char* expression) {

    Pilha* pilhaA = create_stack();
	Pilha* pilhaB = create_stack();

	for(int i = 0; i < strlen(expression); i++){

        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(expression[i], pilhaA);
        } else {
            char element = pop(pilhaA);
            if(element == '(' && expression[i] != ')') {
                return false;
            } else if(element == '[' && expression[i] != ']') {
                return false;
            } else if(element == '{' && expression[i] != '}') {
                return false;
            } else if(element == '\0') {
                return false;
            }
        }

    }

    if(strlen(expression) % 2 != 0) {
        return false;
    }

    return true;
	
}

int main() {

	char* expression[100];// = (char*) malloc(100* sizeof(char));
	scanf("%s", expression);

	printf("\n%s", is_valid(expression) ? "é uma expressão válida" : "não é uma expressão válida");

	return 0;
}