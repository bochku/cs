#ifndef _STACK
#define _STACK

#include "../llist/llist.h"

template <class T>
class Stack {
    public:
        List<T> _list;
        bool empty() {      return _list.isEmpty(); }
        void push(T d) {    _list.addFront(d); }
        T pop() {           return _list.remFront(); }
        T peek() {          return _list.head->data; }
};

#endif // _STACK
