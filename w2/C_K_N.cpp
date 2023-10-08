#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const unsigned long long int mod = 1e9+7;

unsigned long long int C(int k, int n) {
    unsigned long long int a[n+1][k+1];
    
    for (int i = 0; i <= n; ++i) {
        for (int j = max(k-n+i, 0); j <= min(i, k); ++j) {
            if (j == 0 || j == i) {
                a[i][j] = 1;
            } else if (j == 1) {
                a[i][j] = i;
            } else {
                a[i][j] = (a[i-1][j-1] + a[i-1][j]) % mod;
            }
        }
    }
    
    return a[n][k];
}

int main() {
    int k, n;
    cin >> k >> n;
    
    cout << C(min(k, n-k), n);
    
    
    return 0;
}
