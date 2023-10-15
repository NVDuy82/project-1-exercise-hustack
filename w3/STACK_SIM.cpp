#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main() { 
    stack<int> s;
    string str;
    do {
        cin >> str;
        if (str == "POP") {
            if (s.empty()) {
                cout << "NULL" << endl;
            } else {
                int temp = s.top();
                s.pop();
                cout << temp << endl;
            }
        } else if (str == "PUSH") {
            int temp;
            cin >> temp;
            s.push(temp);
        }
    } while (str != "#");
    return 0;
}
