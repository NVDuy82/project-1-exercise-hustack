#include <iostream>

using namespace std;

int n, M;
int a[11];

void print_sol() {
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void try_func(int x, int max) {
    if (x != n) {
        for (int i = 1; i <= max; ++i) {
            a[x] = i;
            try_func(x+1, max - i + 1);
        }
    } else {
        a[x] = max;
        print_sol();
    }
}

int main() {
    cin >> n >> M;
    
    try_func(1, M - n + 1);
    
    return 0;
}
