#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    Queue<int> Q;
    for (int i=0; i<10; i++ ) Q.enq(i);
    while (!Q.empty()){
        cout << Q.deq() << endl;
    }
    return 0;
}
