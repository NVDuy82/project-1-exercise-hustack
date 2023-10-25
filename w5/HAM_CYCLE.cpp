#include <iostream>
#include <cstring>

using namespace std;

inline void solve() {
    int n, m;
    cin >> n >> m;
    
    int deg[n+1];
    memset(deg, 0, sizeof(deg));
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        ++deg[u];
        ++deg[v];
    }
    
    for (int u = 1; u <= n; ++u) {
        if (deg[u] < 2) {
            cout << false << endl;
            return;
        }
    }
    
    cout << true << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
