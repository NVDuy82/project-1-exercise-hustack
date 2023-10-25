#include <iostream>
#include <vector>
#include <queue>
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
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            q.push(i);
            
            while (!q.empty()) {
                int front = q.front();
                q.pop();
                
                if (visited[front]) continue;
                visited[front] = true;
                cout << front << " ";
                
                for (int i: adj[front]) {
                    q.push(i);
                }
            }
        }
    }
    
    return 0;
}
