#include <stdio.h>
#include <iostream>

using namespace std;

void intercala(int vetor[], int inicio, int meio, int fim) {
   int n1 = meio - inicio + 1;
   int n2 = fim - meio;

   int L[n1], M[n2];

   for (int i = 0; i < n1; i++)
      L[i] = vetor[inicio + i];
   for (int j = 0; j < n2; j++)
      M[j] = vetor[meio + 1 + j];

   int i, j, k;
   i = 0;
   j = 0;
   k = inicio;

   while (i < n1 && j < n2) {
      if (L[i] <= M[j]) {
         vetor[k] = L[i];
         i++;
      }
      else {
         vetor[k] = M[j];
         j++;
      }
      k++;
   }

   while (i < n1) {
      vetor[k] = L[i];
      i++;
      k++;
   }

   while (j < n2) {
      vetor[k] = M[j];
      j++;
      k++;
   }
}

void merge_sort(int v[], int inicio, int fim) {

   if(inicio < fim) {
      int m = inicio + (fim - inicio) / 2;

      merge_sort(v, inicio, m);
      merge_sort(v, m + 1, fim);

      intercala(v, inicio, m, fim);
   }
}

int main() {
   int vetor[6] = {7, 9, 4, 3, 6, 1};

   merge_sort(vetor, 0, 5);

   printf("\n2.Vetor ordenado:\n");
   for (int i = 0; i <= 5; i++) {
      printf("%d ", vetor[i]);
   }
   printf("\n");

   return 1;
}