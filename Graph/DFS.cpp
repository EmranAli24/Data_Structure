#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int node, const vector<vector<int>> &adj, vector<bool> &vis, vector<int> &result) {
        vis[node] = true;
        result.push_back(node);
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis, result);
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, const vector<vector<int>> &adj) {
        vector<bool> vis(V, false);
        vector<int> result;
        dfs(0, adj, vis, result);
        return result;
    }
};

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Omit this line if the graph is directed
}

void printAns(const vector<int> &ans) {
    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(V, adj);
    printAns(ans);

    return 0;
}
