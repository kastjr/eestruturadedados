#include "./pilha.c"

int main() {
    Pilha *pilha = criar_pilha(100);

    push(pilha, 8);

    while (getTopo(pilha) > 0) {
        push(pilha, pilha->vetor[getTopo(pilha)] / 2);
    }

    while (!pilhaVazia(pilha)) {
        printf("%f\n", pop(pilha)); // 0.000000 para todos pops
    }
}