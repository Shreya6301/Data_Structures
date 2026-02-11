#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS function to detect cycle
bool bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<pair<int, int>> q;   // (node, parent)

    visited[start] = true;
    q.push({start, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : graph[node]) {

            // If not visited, add to queue
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            }

            // If visited and not parent → cycle
            else if (neighbor != parent) {
                return true;
            }
        }
    }

    return false;
}

// Check cycle in entire graph
bool hasCycle(int n, vector<vector<int>>& graph) {
    vector<bool> visited(n, false);

    // For disconnected graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (bfs(i, graph, visited))
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
