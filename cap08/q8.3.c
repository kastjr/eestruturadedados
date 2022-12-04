#include <stdio.h>

void troca(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void empurra(int v[], int n) {
    for(int i = 0; i < n; i++)
        if(v[i] > v[i+1])
            troca(&v[i], &v[i+1]);
}

void bubble_sort(int v[], int n) {
    if(n > 0) {
        empurra(v, n);
        bubble_sort(v, n-1);
    }
}

int main() {

    int v[5] = {3, 4, 1, 7, 2};
    bubble_sort(v, 4);

    for(int i = 0; i < 5; i++)
        printf("%d ", v[i]);

    return 0;
}