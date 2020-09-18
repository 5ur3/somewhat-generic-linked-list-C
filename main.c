#include "linkedlist/linkedlist.h"
#include <stdio.h>

void printIntLinkedList(LinkedList *list) {
	for (LinkedListElement *element = list->first; element != 0; element = element->next)
		printf("%d ", ll_getValue_int(element));
	printf("\n");
}

int main() {
    LinkedList *list = ll_create();
    for (int i = 0; i < 10; i++)
        ll_push_int(list, i);
	printIntLinkedList(list);

	ll_insert_int(list, 5, 55);
	printIntLinkedList(list);

	ll_remove(list, 6);
	printIntLinkedList(list);

	ll_set_int(list, 5, 5);
	printIntLinkedList(list);

	printf("%d\n", ll_pop_int(list));
	printIntLinkedList(list);

	ll_destroy(list);
    return 0;
}
