#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v;
    
    for (int i = n; i != 0; --i) {
        v.push_back(i);
    }
    
    vector<int> v_end(n);
    v_end = v;
    
    do {
        next_permutation(v.begin(), v.end());
        for (auto item : v) {
            cout << item << " ";
        }
        cout << endl;
    } while (v != v_end);
    
    return 0;
}
