#include <iostream>
#include <unordered_map>

using namespace std;


int main() {
    int n, M;
    cin >> n >> M;
    
    int a[n];
    int count = 0;
    unordered_map<int, bool> check;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (check[a[i]]) count++;
        check[M - a[i]] = true;
    }
    
    cout << count << endl;
    
    return 0;
}
