#include "gen_int_list.h"

// função implementada em gen_int_list.h

/*
int get_value(int index_value, List* list) {
    if(is_empty(list)) {
        return '\0';
    }
    if(index_value == 0) {
        return list->value;
    }
    return get_value(index_value - 1, list->next);
}
*/

main() {

	List* lista = create_list(1);

    add_last(2, lista);
    add_last(3, lista);
    add_last(4, lista);
    add_last(5, lista);

    printf("%d\n", get_value(2, lista)); // 3
}