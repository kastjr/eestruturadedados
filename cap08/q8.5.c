#include <stdio.h>

void insere(int x, int v[], int n) {
    while(n > 0 && x < v[n-1]) {
        v[n] = v[n-1];
        n--;
    }
    v[n] = x;
    
}

void insertion_sort(int v[], int n) {
    if(n == 1) {
        return;
    } 
    n--;
    insertion_sort(v, n);
    insere(v[n], v, n);
}

int main() {
    int v[] = {15, 2, 42, 28, -2, 5, 15, -1, 43};

    insertion_sort(v, 9);

    for (int i = 0; i < 9; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}