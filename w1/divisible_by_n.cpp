#include <iostream>

using namespace std;

int main() {
    int n; // number of elements
    cin >> n; // input n
    
    for (int i = (99 / n + 1) * n; i < 1000; i += n) {
        cout << i << " ";
    }
    
    return 0;
}
