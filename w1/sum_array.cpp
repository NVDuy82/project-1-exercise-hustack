#include <iostream>

using namespace std;

int main() {
    int n; // number of elements
    cin >> n; // input n
    
    int temp; // save the value of element
    int sum = 0; // sum array
    
    for (int i = 0; i < n; ++i) { // loop
        cin >> temp; // input value of element
        sum += temp;
    }
    
    cout << sum << endl;
    
    return 0;
}
