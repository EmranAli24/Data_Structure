#include <iostream>
#include <vector>
using namespace std;

bool dfsDirected(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfsDirected(neighbor, adj, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            return true;  // cycle found
        }
    }

    recStack[node] = false;
    return false;
}

bool hasCycleDirected(int n, vector<vector<int>> &adj) {
    vector<bool> visited(n + 1, false), recStack(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (dfsDirected(i, adj, visited, recStack))
                return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cout << "\nDirected Graph\n";
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    cout << "Enter " << m << " directed edges:\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (hasCycleDirected(n, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle detected\n";

    return 0;
}

/*
4 4

1 2
2 3
3 4
4 2

Output: cycle detected.

*/