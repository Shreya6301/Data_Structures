#include <iostream>
#include <vector>

using namespace std;

// DFS utility function (recursive)
void dfsUtil(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    // Mark current node as visited
    visited[node] = true;

    // Process the node
    cout << node << " ";

    // Visit all unvisited neighbors
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, graph, visited);
        }
    }
}

// DFS function
void dfs(int start, vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);  // Visited array

    cout << "DFS Traversal: ";

    dfsUtil(start, graph, visited);
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

    dfs(start, graph, n);

    return 0;
}
