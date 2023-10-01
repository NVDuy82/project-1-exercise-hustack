#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    double d = b * b - 4 * a * c;
    
    if (d < 0) {
        cout << "NO SOLUTION" << endl;
    } else if (d == 0) {
        cout << fixed << setprecision(2) << - b / (2.0 * a);
    } else {
        cout << fixed << setprecision(2) << (- b - sqrt(d)) / (2.0 * a);
        cout << " ";
        cout << fixed << setprecision(2) << (- b + sqrt(d)) / (2.0 * a);
    }
    
    return 0;
}
