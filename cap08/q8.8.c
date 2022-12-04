#include <time.h>
#include <stdio.h>

int particiona(int v[], int p, int u) {
    int x = v[p];
    p--;
    u++;
    while(p < u) {
        do u--; while(v[u] > x);
        do p++; while(v[p] < x);
        if(p < u) {
            int aux = v[p];
            v[p] = v[u];
            v[u] = aux;
        }
    }
    return u;
}

void quick_sort(int v[], int p, int u) {
    if(p >= u) return;
    int m = particiona(v, p, u);
    quick_sort(v, p, m);
    quick_sort(v, m + 1, u);
}

int main() {
    int v1[7] = {72, 69, 51, 46, 33, 28, 15};
    int v2[7] = {46, 28, 51, 33, 72, 15, 69};

    clock_t begin = clock();
    quick_sort(v1, 0, 6);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    clock_t begin2 = clock();
    quick_sort(v2, 0, 6);
    clock_t end2 = clock();
    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;

    for(int i = 0; i < 7; i++) {
        printf("%d ", v1[i]);
    }
    printf("  tempo gasto: %.7f", time_spent); // 0.0000010

    printf("\n");

    for(int i = 0; i < 7; i++) {
        printf("%d ", v2[i]);
    }
    printf("  tempo gasto: %.7f", time_spent2); // 0.0000012

    printf("\n");

    return 0;
}
