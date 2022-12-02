#include "gen_int_list.h"

// função implementada em gen_int_list.h

/*
int equals(List* list1, List* list2) {
    if(list1 == NULL && list2 == NULL) {
        return 1;
    }
    if(list1 != NULL && list2 != NULL && list1->value == list2->value) {
        return equals(list1->next, list2->next);
    }
    return 0;
}
*/

main() {

	List* lista1 = create_list(1);

    add_last(2, lista1);
    add_last(1, lista1);
    add_last(2, lista1);

    List* lista2 = create_list(1);

    add_last(3, lista2);
    add_last(1, lista2);
    add_last(3, lista2);

    List* lista3 = create_list(1);

    add_last(2, lista3);
    add_last(1, lista3);
    add_last(2, lista3);

    printf("%d\n", equals(lista1, lista2)); // 0 falso
    printf("%d\n", equals(lista1, lista3)); // 1 verdadeiro
}