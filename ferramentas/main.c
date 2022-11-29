#include "pilha.c"

int main() {
    Pilha *pilha_1 = criar_pilha(5);

    preencher_pilha(pilha_1);

    printf("%d\n", pilha_1->topo);

    printf("%d\n", pop_em_valor(pilha_1, 7));

    // mostrar_valores(pilha_1);
    // mostrar_valores(pilha_2);
}