#include "listord.h"

void exibir_decrescente(List* list) {
    if(list == NULL) return;
    exibir_decrescente(list->next);
    printf("%d\n", list->value);
}

int main() {

    List* lista1 = create_list(4);

    ins(3, lista1);
    ins(2, lista1);
    ins(6, lista1);
    ins(5, lista1);

    exibir_decrescente(lista1);
    return 1;
}