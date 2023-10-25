#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    // Sequence of nodes visited by BFS
    vector<bool> visited(n + 1, false);
    stack<int> s;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            s.push(i);
            
            while (!s.empty()) {
                int top = s.top();
                s.pop();
                
                if (visited[top]) continue;
                visited[top] = true;
                cout << top << " ";
                
                for (int i: adj[top]) {
                    s.push(i);
                }
            }
        }
    }
    
    return 0;
}
