#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        } else if (neighbor != parent) {
            return true;  // back edge found
        }
    }
    return false;
}

bool hasCycle(int n, vector<vector<int>> &adj) {
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cout << "Undirected Graph\n";
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    cout << "Enter " << m << " undirected edges:\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (hasCycle(n, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle detected\n";

    return 0;
}

/*
Input: 
5 5

1 2
2 3
3 4
4 5
5 2

Output: Cycle Detected. 


*/