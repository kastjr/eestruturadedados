#include "listord.h"

// função implementada em listord.h

/*
void insSR(int new_value, List* list) {
    List* last;
    while(list != NULL && list->value < new_value) {
        last = list;
        list = list->next;
    }
    if(list == NULL) {
        last->next = create_list(new_value);
    } else if(list->value != new_value) {
        List* novo = create_list(list->value);
        novo->next = list->next;
        list->value = new_value;
        list->next = novo;
    }
}
*/

int main() {

    List* lista1 = create_list(4);

    insSR(3, lista1);
    insSR(2, lista1);
    insSR(2, lista1);
    insSR(5, lista1);

    show(lista1);
    return 1;
}