#include "gen_int_list.h"

// função implementada em gen_int_list.h

/*
void replace_value(int old_value, int new_value, List* list) {
    if(list == NULL) {
        return;
    }
    if(list->value == old_value) {
        list->value = new_value;
    }
    replace_value(old_value, new_value, list->next);
}
*/

main() {

	List* lista = create_list(1);

    add_last(2, lista);
    add_last(1, lista);
    add_last(2, lista);

    replace_value(2, 3, lista);

	show(lista); // 1, 3, 1, 3
}