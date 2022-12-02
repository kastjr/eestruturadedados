#include "gen_int_list.h"

// função implementada em gen_int_list.h

/*
int ocurrences(int value, List* list) {
    Item* current = list->first;
    int counter = 0;
    while(current != NULL) {
        if(current->value == value) {
            counter++;
        }
        current = current->next;
    }
    return counter;
}
*/

main() {

	List* lista = create_list(1);

    add_last(2, lista);
    add_last(1, lista);
    add_last(4, lista);
    add_last(1, lista);

	printf("%d\n", ocurrences(1, lista)); // 3