#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct item {

    int value;
    struct item* next;

} List;

List* create_list(int value) {

    List* list = (List*) malloc(sizeof(List*));

    list->value = value;
    list->next = NULL;

    return list;
}

int is_empty(List* list) {

    return (list == NULL);
}

List* find(int value, List* list) {

    List* current = list;

    while(current->next != NULL) {
        if(current->next->value == value) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

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

void add_last(int value, List* list) {

    List* last = find_last(list);

    if(is_empty(list)) {
        list = create_list(value);
    } else {
        last->next = create_list(value);
    }
}

void add_first(int value, List* list) {	

    List* new_item = create_list(value);

    if(is_empty(list)) {
        list = new_item;
    } else {
        new_item->next = list;
        list = new_item;
    }
}

int remove_value(int value, List* list) {

    List* tormv = find(value, list);

    if(tormv == NULL) {
        return 0;
    }

    if(tormv->value == value) {
        free(list);
        list = NULL;
        return 1;
    }

    List* aux = tormv->next;
    tormv->next = tormv->next->next;
    free(aux);
    return 1;
}

void remove_all(List* list) {

    List* current = list;
    List* next = NULL;

    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;						
    }

    list = current;
}

void show(List* list) {
    if (is_empty(list)) {
        return;
    }

    List* current = list;

    while(current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

int ocurrences(int value, List* list) {

    List* current = list;
    int counter = 0;

    while(current != NULL) {
        if(current->value == value) {
            counter++;
        }
        current = current->next;
    }

    return counter;
}

int sum(int soma, List* list) {

    if(list == NULL) {
        return soma;
    }

    return (soma + sum(list->value, list->next));
}

void replace_value(int old_value, int new_value, List* list) {

    if(list == NULL) {
        return;
    }

    if(list->value == old_value) {
        list->value = new_value;
    }

    replace_value(old_value, new_value, list->next);
}

int equals(List* list1, List* list2) {

    if(is_empty(list1) && is_empty(list2)) {
        return 1;
    }

    if(!is_empty(list1) && !is_empty(list2) && list1->value == list2->value) {
        return equals(list1->next, list2->next);
    }

    return 0;
}

int get_value(int index_value, List* list) {

    if(is_empty(list)) {
        return '\0';
    }

    if(index_value == 0) {
        return list->value;
    }

    return get_value(index_value - 1, list->next);
}