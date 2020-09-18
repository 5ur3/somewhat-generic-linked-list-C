#include <stdlib.h>
#define TOKENPASTE(x, y) x##y

#ifndef NAME
#define NAME_DEFINED_HERE
#define NAME TYPE
#endif

#define ll_getValue_(T) TOKENPASTE(ll_getValue_, T)
TYPE ll_getValue_(NAME)(LinkedListElement *element) {
    return *((TYPE *)(element->value));
}
#define ll_get_(T) TOKENPASTE(ll_get_, T)
TYPE ll_get_(NAME)(LinkedList *list, int index) {
    return ll_getValue_(NAME)(ll_get(list, index));
}
#define ll_create_element_(T) TOKENPASTE(ll_create_element_, T)
LinkedListElement *ll_create_element_(NAME)(TYPE value) {
    TYPE *value_p = malloc(sizeof(TYPE));
    *value_p = value;
    LinkedListElement *element = malloc(sizeof(LinkedListElement));
    element->value = value_p;
    return element;
}
#define ll_push_(T) TOKENPASTE(ll_push_, T)
void ll_push_(NAME)(LinkedList *list, TYPE value) {
    return ll_push(list, ll_create_element_(NAME)(value));
}
#define ll_insert_(T) TOKENPASTE(ll_insert_, T)
void ll_insert_(NAME)(LinkedList *list, int index, TYPE value) {
    return ll_insert(list, index, ll_create_element_(NAME)(value));
}
#define ll_insertToElement_(T) TOKENPASTE(ll_insertToElement_, T)
void ll_insertToElement_(NAME)(LinkedList *list,
                               LinkedListElement *toListElement, TYPE value) {
    return ll_insertToElement(list, toListElement,
                              ll_create_element_(NAME)(value));
}
#define ll_pop_(T) TOKENPASTE(ll_pop_, T)
TYPE ll_pop_(NAME)(LinkedList *list) {
    LinkedListElement *element = ll_pop(list);
    TYPE value = *(TYPE *)(element->value);
    free(element->value);
    free(element);
    return value;
}
#define ll_setElement_(T) TOKENPASTE(ll_setElement_, T)
void ll_setElement_(NAME)(LinkedListElement *element, TYPE value) {
    TYPE *value_p = malloc(sizeof(TYPE));
    *value_p = value;
	return ll_setElement(element, value_p);
}
#define ll_set_(T) TOKENPASTE(ll_set_, T)
void ll_set_(NAME)(LinkedList *list, int index, TYPE value) {
	TYPE *value_p = malloc(sizeof(TYPE));
    *value_p = value;
	return ll_set(list, index, value_p);
}

#ifdef NAME_DEFINED_HERE
#undef NAME
#endif
