/** circular queues using arrays */

#include <iostream>
using namespace std;


#define DEFAULT_SIZE 100

class CQ {
    public:
        int *data;
        int head, tail;
        int size, count;

        CQ( int s=DEFAULT_SIZE ) {
            data = new int[s];
            size = s;
            head = tail = -1;
            count = 0;
        }

        ~CQ() {
            delete[] data;
        }

        bool empty() { return count == 0; }
        bool full()  { return count == size; }
        int peek()   { return data[head]; }

        void enq( int d ) {
            if (full()) {
                cout << "Error: queue full" << endl;
                return;
            }
            if (empty()) head = 0;
            tail = (tail+1)%size;
            data[tail] = d;
            count += 1;
        }

        int deq() {
            if (empty()) {
                cout << "Error: queue empty" << endl;
                return -1;
            }
            int d = data[head];
            data[head] = 0; // TODO: comment out this line when done.
            if ( count == 1 ) 
                head = tail = -1;
            else head = (head+1)%size;
            count -= 1;
            return d;
        }

        void show() {
            for (int i=0; i<size; i++) {
                if (i == head) cout << "*";
                if (i == tail) cout << "#";
                cout << data[i] << ",\t" ;
            }
            cout << endl;
        }
};

int main() { 
    CQ q( 10 );
    int count = 0;
    for (int i=0; i< 7; i++ ) {
        q.enq(count ++ );
        q.show();
    }
    
    cout << endl << endl;

    for ( int i=0; i < 3; i ++ )  {
        int k = q.deq();
        cout << "dequed " << k << ", queue: ";
        q.show();
    }
    
    cout << endl << endl;

    for (int i=0; i< 5; i++ ) {
        q.enq(count ++ );
        q.show();
    }
    
    cout << endl << endl;

    while ( !q.empty() ) {
        int k = q.deq();
        cout << "dequed " << k << ", queue: ";
        q.show();
    }

    return 0;
}

