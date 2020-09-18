#include <stdlib.h>

typedef struct LListElement {
    struct LListElement *prev;
    struct LListElement *next;
    LL_TYPE *value;
} llistElement;
typedef struct LList {
    llistElement *first;
    llistElement *last;
    int size;
} llist;

void _ll_init(llist *list) {
    list->size = 0;
    list->first = 0;
    list->size = 0;
}
llist ll_create() {
    llist list;
    _ll_init(&list);
    return list;
}
llistElement *ll_getElement(llist *list, int index) {
    if (list->size == 0 || index < 0 || index >= list->size)
        return 0;
    if (index <= list->size / 2) {
        llistElement *element = list->first;
        for (int i = 0; i < index; i++)
            element = element->next;
        return element;
    } else {
        llistElement *element = list->last;
        for (int i = list->size - 1; i > index; i--)
            element = element->prev;
        return element;
    }
}
void ll_push(llist *list, LL_TYPE element) {
    if (list->size == 0) {
        LL_TYPE *elementP = (LL_TYPE *)(malloc(sizeof(LL_TYPE)));
        *elementP = element;
        llistElement *listElement =
            (llistElement *)(malloc(sizeof(llistElement)));
        listElement->value = elementP;
        listElement->prev = 0;
        listElement->next = 0;

        list->first = listElement;
        list->last = listElement;
        list->size = 1;
    } else {
        LL_TYPE *elementP = (LL_TYPE *)(malloc(sizeof(LL_TYPE)));
        *elementP = element;
        llistElement *listElement =
            (llistElement *)(malloc(sizeof(llistElement)));
        listElement->value = elementP;
        listElement->prev = list->last;
        listElement->next = 0;

        list->last->next = listElement;
        list->last = listElement;
        list->size++;
    }
}
void ll_insert(llist *list, int index, LL_TYPE value);
void ll_insertToElement(llist *list, llistElement *toListElement,
                        LL_TYPE value) {
    if (list->first == toListElement)
        return ll_insert(list, 0, value);

    LL_TYPE *elementP = (LL_TYPE *)(malloc(sizeof(LL_TYPE)));
    *elementP = value;
    llistElement *newListElement =
        (llistElement *)(malloc(sizeof(llistElement)));
    newListElement->value = elementP;

    toListElement->prev->next = newListElement;
    newListElement->prev = toListElement->prev;
    toListElement->prev = newListElement;
    newListElement->next = toListElement;

    list->size++;
}
void ll_insert(llist *list, int index, LL_TYPE value) {
    if (index < 0 || index > list->size)
        return;
    if (index == list->size)
        return ll_push(list, value);
    if (index == 0) {
        LL_TYPE *elementP = (LL_TYPE *)(malloc(sizeof(LL_TYPE)));
        *elementP = value;
        llistElement *listElement =
            (llistElement *)(malloc(sizeof(llistElement)));
        listElement->value = elementP;
        listElement->prev = 0;
        listElement->next = list->first;
        list->first->prev = listElement;
        list->first = listElement;
        list->size++;
        return;
    }
    llistElement *listElement = ll_getElement(list, index);
    ll_insertToElement(list, listElement, value);
}
LL_TYPE *ll_pop(llist *list) {
    if (list->size == 0) {
        return 0;
    } else if (list->size == 1) {
        LL_TYPE *value = (LL_TYPE *)(list->last->value);
        free(list->last->value);
        free(list->last);
        list->first = 0;
        list->last = 0;
        list->size = 0;
        return value;
    } else {
        LL_TYPE *value = (LL_TYPE *)(list->last->value);
        llistElement *listElementToFree = list->last;
        list->last = listElementToFree->prev;
        free(listElementToFree->value);
        free(listElementToFree);
        list->size--;
        return value;
    }
}
void ll_destroy(llist *list) {
    while (list->size)
        ll_pop(list);
}
void ll_remove(llist *list, int index) {
    if (index < 0 || index >= list->size)
        return;
    if (index == list->size - 1) {
        ll_pop(list);
        return;
    }
    if (index == 0) {
        llistElement *newFirst = list->first->next;
        free(list->first->value);
        free(list->first);
        list->first = newFirst;
        list->first->prev = 0;
        list->size--;
    } else {
        llistElement *elementToRemove = ll_getElement(list, index);
        elementToRemove->next->prev = elementToRemove->prev;
        elementToRemove->prev->next = elementToRemove->next;
        free(elementToRemove->value);
        free(elementToRemove);
        list->size--;
    }
}
LL_TYPE ll_get(llist *list, int index) {
    return *(LL_TYPE *)(ll_getElement(list, index)->value);
}
void ll_setElement(llistElement *listElement, LL_TYPE value) {
    LL_TYPE *elementP = (LL_TYPE *)(malloc(sizeof(LL_TYPE)));
    *elementP = value;
    free(listElement->value);
    listElement->value = elementP;
}
void ll_set(llist *list, int index, LL_TYPE value) {
    ll_setElement(ll_getElement(list, index), value);
}
