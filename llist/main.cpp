/** driver program **/

#include "llist.h"
#include <stdio.h>

int main() {
    List<int> newlist;
    for ( int i=0; i < 10; i++ ) {
        //printf( "Adding %d\n", i );
        newlist.addFront( i );
    }
    //newlist.show();
    //printf( "Press something" );
    getchar();
    while ( !newlist.isEmpty() ) {
        int i = newlist.remBack();
        printf( "%d ", i );
        //getchar();
    }
    printf( "\n" );
    return 0;
}
