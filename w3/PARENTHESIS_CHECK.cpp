#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

const char openBracket[3] = {'(', '[', '{'};
const char closedBracket[3] = {')', ']', '}'};

bool isOpenBracket(char c) {
    return any_of(openBracket, openBracket + 3, [c](char _c) {return c == _c;});
}

bool isClosedBracket(char c) {
    return any_of(closedBracket, closedBracket + 3, [c](char _c) {return c == _c;});
}

char oppositeChar(char c) {
    switch (c) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default: return 0;
    }
}

int main() {
    stack<char> s;
    string str;
    cin >> str;
    
    for (char c : str) {
        if (isOpenBracket(c)) {
            // push  (  [  {  to stack
            s.push(c);
            
        } else if (isClosedBracket(c)) {
            // pop from stack if see  )  ]  }  
            
            if (!s.empty() && s.top() == oppositeChar(c)) {
                // pop from stack
                s.pop();
                
            } else {
                // stack empty or failed closed bracket
                cout << 0 << endl;
                return 0;
            }
        }
    }
    
    if (s.empty()) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}
