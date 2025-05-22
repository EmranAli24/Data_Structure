#include <iostream>
using namespace std;

int main() {

    int n, m; // n = number of nodes & m = number of edges.
    cin >> n >> m;

    // Initialize adjacency matrix with 0
    int adj[n+1][n+1] = {0}; 

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  // Remove this line in case of a directed graph
    }

    // Printing adjacency matrix
    cout << "Adjacency Matrix:\n";
    for(int i = 1; i <= n; i++) { // Assuming 1-based indexing
        for(int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


/*
input: 
// n,m
4 3 
// following m lines 
1 2
2 3
3 4


output: 
Adjacency Matrix:
0 1 0 0 
1 0 1 0 
0 1 0 1 
0 0 1 0 

 The presence of 1 in adj[i][j] indicates an edge between vertex i and vertex j.

*/