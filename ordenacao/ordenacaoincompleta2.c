#include<stdio.h>
#include<iostream>

using namespace std;

void swap(int *a, int *b) {
   int t = *a;
   *a = *b;
   *b = t;
}

int partition(int vetor[], int inicio, int fim) {

   int pivot = vetor[fim];
   int i = (inicio - 1);

   for (int j = inicio; j < fim; j++) {
      if (vetor[j] <= pivot) {
         i++;
         swap(&vetor[i], &vetor[j]);
      }
   }
   swap(&vetor[i + 1], &vetor[fim]);
   return (i + 1);
}

void Quick(int vetor[10], int inicio, int fim) {
   if (inicio < fim) {
      int pi = partition(vetor, inicio, fim);
      Quick(vetor, inicio, pi - 1);
      Quick(vetor, pi + 1, fim);
   }
}

int main() {
   int vetor[6] = {7, 9, 4, 3, 6, 1};
   int i;   

   Quick(vetor, 0, 5);

   printf("2.Vetor ordenado:\n");

   for(i = 0; i <= 5; i++){
      printf("%d ", vetor[i]);
   }

   printf("\n");   

   return 1;
}