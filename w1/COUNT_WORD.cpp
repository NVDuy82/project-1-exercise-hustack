#include <bits/stdc++.h>

using namespace std;

bool isSPACEorTABorLineBreack(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

int main() {
    char c = getchar();
    
    int count = 0;
    while (c != EOF) {
        while (c != EOF) {
            if (!isSPACEorTABorLineBreack(c)) {
                break;
            }
            c = getchar();
        }
        
        while (c != EOF) {
            if (isSPACEorTABorLineBreack(c)) {
                ++count;
                break;
            }
            c = getchar();
        }
    }
    
    cout << count;
    
    return 0;
}
