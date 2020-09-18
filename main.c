#include "linkedlist/linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    LinkedList list = ll_create();
    ll_push_int(&list, 9);
    ll_push_int(&list, 109);
    ll_push_double(&list, 11.1111111);
    ll_set_int(&list, 1, 209);
	ll_push_char(&list, 'A');
	printf("%c\n", ll_pop_char(&list));
    printf("%lf\n", ll_pop_double(&list));
    printf("%d\n", ll_pop_int(&list));
    printf("%d\n", ll_pop_int(&list));
}
