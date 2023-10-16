#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, bool> dict;
    string cmd, key;
    
    while (true) {
        cin >> key;
        if (key == "*") {
            break;
        }
        
        dict[key] = true;
    }
    
    while (true) {
        cin >> cmd;
        if (cmd == "***") {
            break;
        }
        
        cin >> key;
        if (cmd == "find") {
            if (dict[key]) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (cmd == "insert") {
            if (!dict[key]) {
                dict[key] = true;
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    
    return 0;
}
