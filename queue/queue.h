#ifndef _QUEUE
#define _QUEUE
/** Queue data structure */
#include "../llist/llist.h"

template <class T>
class Queue {
    public:
        List<T> _list;
        bool empty() { return _list.isEmpty(); }
        void enq( T d ) { _list.addBack(d); }
        T deq() { return _list.remFront(); }
        T peek() { return _list.head->data; }
};

#endif // _QUEUE
