#include "gen_int_list.h"

// função implementada em gen_int_list.h

/*
List* find_last(List* list) {
    if(is_empty(list)) {
        return NULL;
    }
    if(list->next == NULL) {
        return list;
    }
    List* current = list;
    while(current != NULL) {
        if(current->next == NULL) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
*/

main() {

	List* lista = create_list(1);

    add_last(2, lista);
    add_last(3, lista);
    add_last(4, lista);
    add_last(5, lista);

	printf("%d\n", find_last(lista)->value); // 5
}