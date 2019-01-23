#include <stdio.h>
#include "stack.h"

int main() {
    Stack<int> S;
    for (int i=0; i<10; i++) S.push(i);
    while (!S.empty() ) {
        int i = S.peek();
        printf( "%d ", i );
        S.pop();
    }
    printf( "\n" );
    return 0;
}
