#include <iostream>
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
        default:  return 0;
    }
}

bool isop( char c ) { return precedence(c) > 0; }

string i2p( string expr ) {
    Stack<char> S;
    string inf= "";
    int idx = 0;
    int N = expr.length();
    while (idx < N ) {
        char c = expr[idx];
        if (isop(c)) {
            char ch = S.peek();
            while ( precedence(ch) >= precedence(c) ) {
                S.pop();
                inf.push_back(ch);
                ch = S.peek();
            }
            S.push(c);
        }
        else if ( c=='(' ) {
            S.push(c);
        }
        else if ( c==')' ) {
            char ch = S.peek();
            while ( ch != '(' ) {
                S.pop();
                inf.push_back(ch);
                ch = S.peek();
            }
        }
        else inf += c;
        idx += 1;
    }
    return inf;
}

int main(int argc, char** argv) {
    string S = "(a+(d*c)/x)";
    if (argc > 1) 
        S = argv[1];
    S.insert( 0, 1, '(' );
    S.push_back( ')' );
    cout << i2p(S) << endl;
    return 0;
}

