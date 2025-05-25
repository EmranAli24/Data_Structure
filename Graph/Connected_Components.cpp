#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int countConnectedComponents(int n, vector<vector<int>> &adj) {
    vector<bool> visited(n + 1, false);
    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }

    return components;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);  // 1-indexed

    cout << "Enter " << m << " undirected edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int result = countConnectedComponents(n, adj);
    cout << "Number of connected components: " << result << endl;

    return 0;
}


/*
Input: 

Enter number of nodes and edges: 6 4
Enter 4 undirected edges (u v):
1 2
2 3
4 5
5 6


output: 
Number of connected components: 2



*/