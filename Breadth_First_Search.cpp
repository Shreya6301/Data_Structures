#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS function
void bfs(int start, vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);   // Mark visited nodes
    queue<int> q;                     // Queue for BFS

    // Start node
    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        // Visit all neighbors
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;  // n = vertices, m = edges

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    // Adjacency list
    vector<vector<int>> graph(n);

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // For undirected graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    bfs(start, graph, n);

    return 0;
}
