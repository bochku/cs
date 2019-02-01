/** Linked List data structure. Goes both ways */

#ifndef _LL
#define _LL

template < class T >
class Node {
    public:
        Node<T> *prev, *next;
        T data;
        Node( const T );
        void show(); //WARNING: implemented only for T=int
};

template < class T >
class List {
    public:
        Node<T> *head, *tail;
        List();
        bool isEmpty();
        void addBack(const T);
        void addFront(const T);
        T remBack();
        T remFront();
        void show(); //WARNING: implemented only for T=int
};

// template functions implemented in llist.tcc
#include "llist.tcc"

template <> void Node<int>::show();
template <> void List<int>::show();

#endif // _LL
