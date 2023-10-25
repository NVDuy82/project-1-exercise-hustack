#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<int, int> parent, size_of;

class Edge {
public:
    int u, v, w;
    
    explicit Edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
    
    bool operator < (const Edge &op) const {
        return w < op.w;
    }
};

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool union_uv(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false; // not union
    
    if (size_of[u] < size_of[v]) swap(u, v);
    parent[v] = u;
    size_of[u] += size_of[v];
    return true;
}

int kruskal(vector<Edge> &edges) {
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto & edge : edges) {
        if (union_uv(edge.u, edge.v)) {
            ans += edge.w;
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    // make set
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size_of[i] = 1;
    }
    
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
    }
    
    cout << kruskal(edges) << endl;
    
    return 0;
}
