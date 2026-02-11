#include <iostream>
#include <vector>

using namespace std;

// DFS function to detect cycle
bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : graph[node]) {

        // If neighbor not visited, recurse
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, graph, visited))
                return true;
        }

        // If visited and not parent → cycle
        else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

// Function to check cycle in graph
bool hasCycle(int n, vector<vector<int>>& graph) {
    vector<bool> visited(n, false);

    // Handle disconnected graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, graph, visited))
                return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (hasCycle(n, graph))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}
