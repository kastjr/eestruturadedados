#include <stdio.h>
#include <string.h>

void insere(char* x, char* v[], int n) {
    while(n > 0 && strcmp(x, v[n-1]) < 0) {
        v[n] = v[n-1];
        n--;
    }
    v[n] = x;
}

void insertion_sort(char** v, int n) {
    for(int i = 0; i < n; i++) {
        insere(v[i], v, i);
    }
}

int main() {
    char* vetor[5];
    vetor[0] = "abcd";
    vetor[1] = "abc";
    vetor[2] = "ab";
    vetor[3] = "xyz";
    vetor[4] = "abd";

    for(int i = 0; i < 5; i++) {
        printf("%s\n", vetor[i]);
    }

    insertion_sort(vetor, 5);
    printf("\nordenada:\n");

    for(int i = 0; i < 5; i++) {
        printf("%s\n", vetor[i]);
    }

    return 1;
}