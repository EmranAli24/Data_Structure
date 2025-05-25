#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int col, vector<int>& color, vector<int> adj[]) {
        color[node] = col;

        for (int it : adj[node]) {
            if (color[it] == -1) {
                if (!dfs(it, !col, color, adj))
                    return false;
            } else if (color[it] == col) {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, adj))
                    return false;
            }
        }
        return true;
    }
};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    map<char, int> charToIndex;
    map<int, char> indexToChar;
    set<char> vertices;
    vector<pair<char, char>> edges;

    cout << "Enter " << E << " edges using capital letters (e.g., A B):" << endl;
    for (int i = 0; i < E; i++) {
        char u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
        vertices.insert(u);
        vertices.insert(v);
    }

    int idx = 0;
    for (char ch : vertices) {
        charToIndex[ch] = idx;
        indexToChar[idx] = ch;
        idx++;
    }

    int V = vertices.size();
    vector<int> adj[V];

    for (int i = 0; i < edges.size(); i++) {
        char u = edges[i].first;
        char v = edges[i].second;
        addEdge(adj, charToIndex[u], charToIndex[v]);
    }

    Solution obj;
    bool ans = obj.isBipartite(V, adj);
    cout << (ans ? "1\n" : "0\n");
    return 0;
}
