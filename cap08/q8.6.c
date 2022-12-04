#include <stdio.h>

int linearSearch(int x, int v[], int n) {
    if(n - 1 == -1) return 0;
    if(x = v[n - 1]) return 1;
    else return linearSearch(x, v, n--);
}

int main() {
    int v[5] = {1, 3, 5, 7, 9};
    int result = linearSearch(1, v, 5);

    printf(result ? "elemento encontrado\n" : "elemento não encontrado\n");

    return 0;
}