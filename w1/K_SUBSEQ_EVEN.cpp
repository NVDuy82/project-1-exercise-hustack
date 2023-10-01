#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int a[n];
    int count = 0, sum = 0;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 0) {
        count++;
    }
    for (int i = k; i < n; ++i) {
        cin >> a[i];
        sum += a[i] - a[i - k];
        if (sum % 2 == 0) {
            count++;
        }
    }
    cout << count;
    
    return 0;
}
