/** template definitions for llist.h */

#include <stdio.h>
#include "llist.h"

template <class T>
Node<T>::Node( const T d ) {
    data= d;
    prev = NULL;
    next = NULL;
}

template <class T>
List<T>::List() { head = tail = NULL; }

template <class T>
bool List<T>::isEmpty() { return head == NULL; }

template <class T>
void List<T>::addBack( const T d ) {
    Node<T> *n = new Node<T> ( d );
    if ( isEmpty() ) head = tail = n;
    else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

template <class T>
void List<T>::addFront( const T d ) {
    Node<T> *n = new Node<T> ( d );
    if ( isEmpty() ) head = tail = n;
    else {
        head->prev = n;
        n->next = head;
        head = n;
    }
}

template <class T>
T List<T>::remFront() {
    if ( isEmpty() ) printf( "Error: accessing empty list" );
    else { 
        Node<T> *tmp = head;
        head= head->next;
        if (head == NULL) tail = NULL;
        else head->prev= NULL;
        T d = tmp->data;
        delete tmp;
        return d;
    }
}

template <class T>
T List<T>::remBack() {
    if ( isEmpty() ) printf( "Error: accessing empty list" );
    else { 
        Node<T> *tmp = tail;
        tail = tail->prev;
        if (tail == NULL) head = NULL;
        else tail->next = NULL;
        T d = tmp->data;
        delete tmp;
        return d;
    }
}
