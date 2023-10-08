#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[21];
int n;

void print_sol() {
    for (int i = 1; i <= n; ++i) {
        cout << a[i];
    }
    cout << endl;
}

void find(int i, int limit) {
    for (int j = 0; j < limit; ++j) {
        a[i] = j;
        
        if (i != n) {
            find(i+1, j ? 1 : 2);
        } else {
            print_sol();
        }
    }
}

int main() {
    cin >> n;
    find(1, 2);
    
    return 0;
}
