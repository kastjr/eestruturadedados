#include <stdio.h>

#define troca(a, b) {int x = a; a = b; b = x; }

int seleciona(int v[], int n){
    int i = 0;
    for(int j=1; j<n; j++)
        if(v[i] < v[j]) i = j;
    return i;
}

void selection_sort(int v[], int n){
    if(n == 0) return;
    troca(v[seleciona(v, n)], v[n-1]);
    n--;
    selection_sort(v, n);
}

int main(){
    int v[] = {15, 2, 42, 28, -2, 5, 15, -1, 43};
    selection_sort(v, 8);

    for (int i = 0; i < 9; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");

    return 0;
}

//fiz sozinho com ajuda dos colegas que ja tinha dupla