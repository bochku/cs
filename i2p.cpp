#include <iostream>
#include <stdio.h>
#include "stack/stack.h"
#include <string>
using namespace std;

int precedence( char op ) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case '(':
        case ')': return -1;
        default:  return 0;
    }
}

bool is_right_associative( char c ) {
    switch( c ) {
        case '^': return true;
        default: return false;
    }
}

string i2p( string I ) {
    Stack<char> S;
    string P = "";
    char c, cnew;
    for ( int idx = 0; idx < I.length(); idx++ ) {
        c = I[idx];
        if ( precedence(c) > 0 ) {
            // c is an operator.
            cnew = S.peek();
            while ( precedence(cnew) >= precedence(c) ) {
                if (cnew == c && is_right_associative(c) ) 
                    // if the operator is right associative then
                    // just come out of the loop and push it to
                    // the stack.
                    break;
                cnew = S.pop();
                P += cnew;
                cnew = S.peek();
            }
            S.push(c);
        }
        else if ( c == '(' )  S.push(c);
        else if ( c == ')' ) {
            cnew = S.peek();
            while ( cnew != '(' ) {
                cnew = S.pop();
                P += cnew;
                cnew = S.peek();
            }
            S.pop();
        }
        else P += c;
    }
    return P;
}


string parenthesize( string s ) { 
    s.insert( 0,1,'(');
    s.push_back(')');
    return s;
}

string p2i( string P ) {
    Stack<string> S;
    char c;
    string o1, o2;
    for( int idx=0; idx < P.length(); idx++ ) {
        c = P[idx];
        if ( precedence(c) == 0 ) {
            S.push( &c );
        }
        else {
            // pop two items from the stack and push 
            // the evaluated result, in this case
            // just the new expression
            o1 = S.pop();
            o2 = S.pop();
            S.push( parenthesize(o2 + &c + o1 ));
        }
    }
    string I = S.pop();
    return I;
}

int main(int argc, char** argv) {
    string S = "a+(d*c)/x";
    if (argc > 1) 
        S = argv[1];
    S= parenthesize(S);
    cout << "Input string " << S << endl;
    string S1= i2p( S );
    string S2= p2i( S1);
    cout << "Post-fix notation " << S1 << endl;
    cout << "Infix notation " << S2 << endl;
    return 0;
}
