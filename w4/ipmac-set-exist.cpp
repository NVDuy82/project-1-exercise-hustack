#include <iostream>
#include <unordered_map>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    int a[n];
    unordered_map<int, bool> check;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cout << (check[a[i]] ? "1" : "0") << endl;
        check[a[i]] = true;
    }
    
    return 0;
}
