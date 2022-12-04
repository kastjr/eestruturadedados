#include <stdio.h>

int binarySearch(int x, int v[], int p, int u) {
    if(u >= p) {
        int meio = (p + u)/2;
        if (v[meio] == x) return 1;
        if (v[meio] > x) return binarySearch(x, v, p, meio - 1);
        return binarySearch(x, v, meio + 1, u);
    }
    return 0;
}

int main() {
    int v[8] = {1, 2, 3, 4, 5, 6, 7, 9};

    for(int i = 0; i < 10; i++) {
        int result = binarySearch(i, v, 0, 8);
        printf(result ? "elemento encontrado\n" : "elemento não encontrado\n");
    }

    return 0;
}