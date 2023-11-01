#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Data structure to represent an edge in the graph
struct Edge {
    int v; // endpoint of the edge
    int capacity; // capacity of the edge
    int flow; // current flow on the edge
};

// Function to find an augmenting path in the residual graph using DFS
int dfs(vector<vector<Edge>> &graph, vector<bool> &visited, int u, int t, int minCapacity) {
    if (u == t) {
        return minCapacity;
    }
    visited[u] = true;
    for (Edge &edge: graph[u]) {
        int v = edge.v;
        int residualCapacity = edge.capacity - edge.flow;
        if (!visited[v] && residualCapacity > 0) {
            int bottleneck = dfs(graph, visited, v, t, min(minCapacity, residualCapacity));
            if (bottleneck > 0) {
                // Update the flow and reverse flow along the path
                edge.flow += bottleneck;
                for (Edge &reverseEdge: graph[v]) {
                    if (reverseEdge.v == u) {
                        reverseEdge.flow -= bottleneck;
                        break;
                    }
                }
                return bottleneck;
            }
        }
    }
    return 0;
}

// Function to compute the maximum flow in the graph using the Ford-Fulkerson algorithm
int maxFlow(vector<vector<Edge>> &graph, int s, int t) {
    int maxFlow = 0;
    int bottleneck;
    vector<bool> visited(graph.size(), false);
    
    // Find augmenting paths and update the flow until no more paths exist
    do {
        fill(visited.begin(), visited.end(), false);
        bottleneck = dfs(graph, visited, s, t, INT_MAX);
        maxFlow += bottleneck;
    } while (bottleneck > 0);
    
    return maxFlow;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    int s, t;
    cin >> s >> t;
    
    // Create a graph with N vertices
    vector<vector<Edge>> graph(N + 1);
    
    // Read the edges and their capacities
    for (int i = 0; i < M; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        // Add the forward and reverse edges to the graph
        graph[u].push_back({v, capacity, 0});
        graph[v].push_back({u, 0, 0});
    }
    
    int res = maxFlow(graph, s, t);
    cout << res << endl;
    
    return 0;
}