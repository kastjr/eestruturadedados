#include "gen_int_list.h"

// função implementada em gen_int_list.h

/*
int sum(int soma, List* list) {
    if(list == NULL) {
        return soma;
    }
    return (soma + sum(list->value, list->next));
}
*/

main() {

	List* lista = create_list(1);

    add_last(2, lista);
    add_last(3, lista);
    add_last(4, lista);
    add_last(5, lista);

	printf("%d\n", sum(0, lista)); // 15
}