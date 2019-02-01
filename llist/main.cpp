/** driver program **/

#include "llist.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

template <> void List<string>::show() {
    Node<string> *tmp = head;
    while (tmp != NULL ) {
        std::cout << tmp->data << ", ";
        tmp = tmp->next;
    }
    std::cout << "\n";
}


int main() {
    List<string> L;
    L.addBack( "Hello World" );
    L.addBack( "This is me" );
    L.addBack( "Aditya" );
    L.show();

    while (!L.isEmpty() ) {
        cout << L.remFront() << endl;
    }
    return 0;
}
