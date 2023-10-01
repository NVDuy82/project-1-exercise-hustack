#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a[n], max_ = INT_MIN, min_ = INT_MAX, sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_ = max(max_, a[i]);
        min_ = min(min_, a[i]);
        sum += a[i];
    }
    
    string query;
    bool isQuerying = false;
    while (!isQuerying) {
        cin >> query;
        if (query == "*") isQuerying = true;
    }
    while (isQuerying) {
        cin >> query;
        
        if (query == "find-max") {
            cout << max_ << endl;
        }
        
        if (query == "find-min") {
            cout << min_ << endl;
        }
        
        if (query == "sum") {
            cout << sum << endl;
        }
        
        if (query == "find-max-segment") {
            int start, end, max_segment = INT_MIN;
            cin >> start >> end;
            for (int i = start - 1; i < end; ++i) {
                max_segment = max(max_segment, a[i]);
            }
            cout << max_segment << endl;
        }
        
        if (query == "***") isQuerying = false;
    }
    
    return 0;
}
