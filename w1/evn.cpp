#include <bits/stdc++.h>

using namespace std;

inline int calc(int min, int max, int price, int n) {
    return (n > min) ? ((n > max) ? max - min : n - min) * price : 0;
}

int main() {
    int p_old[6] = {1728, 1786, 2074, 2612, 2919,3015}; // price
    int p_new_[5] = {1728, 2074, 2612, 3111, 3457}; // price
    pair<int, int> range_old[6] = {{0, 50}, {50, 100}, {100, 200}, {200, 300}, {300, 400}, {400, INT_MAX}};
    pair<int, int> range_new_[5] = {{0, 100}, {100, 200}, {200, 400}, {400, 700}, {700, INT_MAX}};
    int n;
    
    cin >> n;  // input
    int bill_old = 0, bill_new_ = 0;
    
    for (int i = 0; i < 6; ++i) {
        bill_old += calc(range_old[i].first, range_old[i].second, p_old[i], n);
    }
    
    for (int i = 0; i < 5; ++i) {
        bill_new_ += calc(range_new_[i].first, range_new_[i].second, p_new_[i], n);
    }

    double res = (bill_new_ - bill_old) * 1.1;
    cout << fixed << setprecision(2) << res << endl;
    
    return 0;
}
