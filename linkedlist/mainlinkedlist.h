#include <stdlib.h>

typedef struct LinkedListElement {
    struct LinkedListElement *prev;
    struct LinkedListElement *next;
    void *value;
} LinkedListElement;
typedef struct {
    LinkedListElement *first;
    LinkedListElement *last;
    int size;
} LinkedList;

void _ll_init(LinkedList *list) {
    list->size = 0;
    list->first = 0;
    list->size = 0;
}
LinkedList ll_create() {
    LinkedList list;
    _ll_init(&list);
    return list;
}
LinkedListElement *ll_get(LinkedList *list, int index) {
    if (list->size == 0 || index < 0 || index >= list->size)
        return 0;
    if (index <= list->size / 2) {
        LinkedListElement *element = list->first;
        for (int i = 0; i < index; i++)
            element = element->next;
        return element;
    } else {
        LinkedListElement *element = list->last;
        for (int i = list->size - 1; i > index; i--)
            element = element->prev;
        return element;
    }
}
void ll_push(LinkedList *list, LinkedListElement *element) {
    if (list->size == 0) {
        element->prev = 0;
        element->next = 0;

        list->first = element;
        list->last = element;
        list->size = 1;
    } else {
        element->prev = list->last;
        element->next = 0;

        list->last->next = element;
        list->last = element;
        list->size++;
    }
}
void ll_insert(LinkedList *list, int index, LinkedListElement *element);
void ll_insertToElement(LinkedList *list, LinkedListElement *toListElement,
                        LinkedListElement *element) {
    if (list->first == toListElement)
        return ll_insert(list, 0, element);

    toListElement->prev->next = element;
    element->prev = toListElement->prev;
    toListElement->prev = element;
    element->next = toListElement;

    list->size++;
}
void ll_insert(LinkedList *list, int index, LinkedListElement *element) {
    if (index < 0 || index > list->size)
        return;
    if (index == list->size)
        return ll_push(list, element);
    if (index == 0) {
        element->prev = 0;
        element->next = list->first;
        list->first->prev = element;
        list->first = element;
        list->size++;
        return;
    }
    LinkedListElement *listElement = ll_get(list, index);
    ll_insertToElement(list, listElement, element);
}
LinkedListElement *ll_pop(LinkedList *list) {
    if (list->size == 0) {
        return 0;
    } else {
        LinkedListElement *element = list->last;
        if (list->size == 1) {
            list->first = 0;
            list->last = 0;
            list->size = 0;
        } else {
            list->last = list->last->prev;
            list->size--;
        }
        return element;
    }
}
void ll_destroy(LinkedList *list) {
    while (list->size) {
        LinkedListElement *element = ll_pop(list);
        free(element->value);
        free(element);
    }
}
void ll_remove(LinkedList *list, int index) {
    if (index < 0 || index >= list->size)
        return;
    if (index == list->size - 1) {
        LinkedListElement *element = ll_pop(list);
        free(element->value);
        free(element);
        return;
    }
    if (index == 0) {
        LinkedListElement *newFirst = list->first->next;
        free(list->first->value);
        free(list->first);
        list->first = newFirst;
        list->first->prev = 0;
        list->size--;
        return;
    }

    LinkedListElement *elementToRemove = ll_get(list, index);
    elementToRemove->next->prev = elementToRemove->prev;
    elementToRemove->prev->next = elementToRemove->next;
    free(elementToRemove->value);
    free(elementToRemove);
    list->size--;
}
void ll_setElement(LinkedListElement *element, void *value) {
    free(element->value);
    element->value = value;
}
void ll_set(LinkedList *list, int index, void *value) {
    return ll_setElement(ll_get(list, index), value);
}
