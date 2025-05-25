#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[], vector<tuple<int, int, int>>& mstEdges)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<int> vis(V, 0); // Visited array to track nodes included in MST
        vector<int> parent(V, -1); // Parent array to store the MST structure
        pq.push({0, {0, -1}}); // Start with node 0, weight 0, and parent -1
        int sum = 0; // Total weight of the MST

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second.first;
            int par = it.second.second;

            if (vis[node] == 1) continue; // Skip if the node is already in the MST

            vis[node] = 1; // Mark the node as visited
            sum += wt; // Add the edge weight to the total sum

            if (par != -1) {
                // Store the edge in the MST
                mstEdges.push_back({par, node, wt});
            }

            // Traverse all adjacent nodes
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edW = it[1];
                if (!vis[adjNode]) {
                    pq.push({edW, {adjNode, node}}); // Push adjacent nodes into the priority queue
                }
            }
        }

        return sum;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj[V]; // Adjacency list to store the graph

    cout << "Enter the edges in the format (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        // Add the edge to the adjacency list
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // Since the graph is undirected
    }

    Solution obj;
    vector<tuple<int, int, int>> mstEdges; // To store the edges of the MST (u, v, weight)
    int sum = obj.spanningTree(V, adj, mstEdges); // Compute the sum of weights of the MST

    // Output the MST edges and their total weight
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (auto edge : mstEdges) {
        cout << get<0>(edge) << " - " << get<1>(edge) << " (Weight: " << get<2>(edge) << ")" << endl;
    }
    cout << "The sum of all the edge weights in the Minimum Spanning Tree: " << sum << endl;

    return 0;
}