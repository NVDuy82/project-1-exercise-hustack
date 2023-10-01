#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    if (s[4] != '-' || s[7] != '-') {
        cout << "INCORRECT";
        return 0;
    } else {
        s[4] = s[7] = ' ';
    }
    
    for (int i = 0; i < 10; ++i) {
        if (i != 4 && i != 7) {
            if (!isdigit(s[i])) {
                cout << "INCORRECT";
                return 0;
            }
        }
    }
    
    if (s[5] > '1' || (s[5] == '1' && s[6] > '2')) {
        cout << "INCORRECT";
        return 0;
    }
    
    if (s[8] > '3' || (s[8] == '3' && s[9] > '1')) {
        cout << "INCORRECT";
        return 0;
    }
    
    for (int i = 0; i < 10; ++i) {
        if ((i != 5 && i != 8) || s[i] != '0') {
            cout << s[i];
        }
    }
    
    return 0;
}
