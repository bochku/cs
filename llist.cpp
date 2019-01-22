/** implementations of various functions for llist.h */

#include <stdio.h>
#include "llist.h"

template <> void Node<int>::show() {
    printf( "%d ", data );
}

template <> void List<int>::show() {
    Node<int> *tmp = head;
    printf( "HEAD -" );
    while (tmp != NULL) {
        printf( " %d -", tmp->data );
        tmp = tmp->next;
    }
    printf( " TAIL\n" );
}
