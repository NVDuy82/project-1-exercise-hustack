#include <iostream>
#include <climits>

#define INF INT_MAX

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n, m;
    std::cin >> n >> m;
    
    int graph[n + 1][n + 1];
    
    // Initialize the graph matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }
    
    // Read the input arcs and weights
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u][v] = w;
    }
    
    // Run the Floyd-Warshall algorithm
    
    int dist[n + 1][n + 1];
    
    // Initialize the solution matrix as the input graph matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = graph[i][j];
            }
        }
    }
    
    // Update dist[][] with the shortest path between every pair of vertices
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // Print the shortest distance matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                std::cout << -1 << " ";
            } else {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}