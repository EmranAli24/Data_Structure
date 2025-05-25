#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(char node, unordered_map<char, bool> &vis, stack<char> &st, unordered_map<char, vector<char>> &adj) {
        vis[node] = true;
        for (auto it : adj[node]) {
            if (!vis[it])
                dfs(it, vis, st, adj);
        }
        st.push(node);
    }

public:
    vector<char> topoSort(vector<char> &nodes, unordered_map<char, vector<char>> &adj) {
        unordered_map<char, bool> vis;
        stack<char> st;

        // Mark all nodes as not visited initially
        for (char node : nodes) vis[node] = false;

        for (char node : nodes) {
            if (!vis[node])
                dfs(node, vis, st, adj);
        }

        vector<char> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main() {
    int E; // number of edges
    cout << "Enter number of edges: ";
    cin >> E;

    unordered_map<char, vector<char>> adj;
    set<char> nodeSet;

    cout << "Enter edges in format <from> <to> (characters):\n";
    for (int i = 0; i < E; i++) {
        char u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        nodeSet.insert(u);
        nodeSet.insert(v);
    }

    // Convert set to vector to keep track of all nodes
    vector<char> nodes(nodeSet.begin(), nodeSet.end());

    Solution obj;
    vector<char> topoOrder = obj.topoSort(nodes, adj);

    cout << "Topological Order: ";
    for (char c : topoOrder) {
        cout << c << " ";
    }
    cout << "\n";

    return 0;
}
