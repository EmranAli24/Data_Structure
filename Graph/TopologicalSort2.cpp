// For one index based. // using DFS 
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]) {
        vis[node] = 1; // Mark the current node as visited
        for (auto it : adj[node]) { // Traverse all adjacent nodes
            if (!vis[it]) // If the adjacent node is not visited
                dfs(it, vis, st, adj); // Recursively call DFS
        }
        st.push(node); // Push the current node to the stack after visiting all its neighbors
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[]) {
        int vis[V + 1] = {0}; // Initialize a visited array to track visited nodes (1-indexed)
        stack<int> st; // Stack to store the topological order
        for (int i = 1; i <= V; i++) { // Iterate through all nodes (1-indexed)
            if (!vis[i]) { // If the node is not visited
                dfs(i, vis, st, adj); // Perform DFS starting from this node
            }
        }

        vector<int> ans; // Vector to store the final topological order
        while (!st.empty()) { // Pop elements from the stack to get the topological order
            ans.push_back(st.top());
            st.pop();
        }
        return ans; // Return the topological order
    }
};

int main() {
    // Define the graph as an adjacency list (1-indexed)
    int V = 6; // Number of vertices
    vector<int> adj[V + 1] = {{}, {2,3}, {4,5}, {4,6}, {5, 6}, {},{}}; // 1-indexed adjacency list
    // Explanation:
    // adj[1] = {}       (Vertex 1 has no outgoing edges)
    // adj[2] = {}       (Vertex 2 has no outgoing edges)
    // adj[3] = {1}      (Vertex 3 points to Vertex 1)
    // adj[4] = {0, 1}   (Vertex 4 points to Vertices 0 and 1)
    // adj[5] = {0, 2}   (Vertex 5 points to Vertices 0 and 2)

    Solution obj; // Create an object of the Solution class
    vector<int> ans = obj.topoSort(V, adj); // Compute the topological sort

    // Print the topological order
    for (auto node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}