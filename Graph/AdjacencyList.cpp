// // For Undirected graph.

// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     // Adjacency list for an undirected graph
//     vector<int> adj[n+1];

//     for(int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u); // Remove this line for a directed graph
//     }

//     // Printing adjacency list
//     cout << "Adjacency List Representation:\n";
//     for(int i = 1; i <= n; i++) { // Assuming 1-based indexing
//         cout << i << " -> ";
//         for(int neighbor : adj[i]) {
//             cout << neighbor << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// /*
// // n,m
// 5 6

// following m lines
// 1 2
// 1 3
// 2 4
// 3 4
// 3 5
// 4 5

// Output: 
// Adjacency List Representation:
// 1 -> 2 3
// 2 -> 1 4
// 3 -> 1 4 5
// 4 -> 2 3 5
// 5 -> 3 4

// */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    // Create adjacency list of size n + 1 (1-based indexing)
    vector<vector<int>> adj(n + 1);

    // Read m edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        // Assuming an undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Print the adjacency list
    for (int i = 1; i <= n; ++i) {
        cout << "Node " << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
