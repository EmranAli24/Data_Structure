#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int V, unordered_map<char, vector<pair<char, int>>> &adj,
                     vector<char> &nodes, vector<tuple<char, char, int>> &mstEdges) {

        typedef pair<int, char> NodeWeightPair;
        priority_queue<NodeWeightPair, vector<NodeWeightPair>, greater<NodeWeightPair>> pq;

        unordered_map<char, bool> vis;
        unordered_map<char, char> parent;
        unordered_map<char, int> key;

        for (char node : nodes) {
            key[node] = INT_MAX;
            vis[node] = false;
        }

        char start = nodes[0];
        pq.push({0, start});
        key[start] = 0;

        int totalWeight = 0;

        while (!pq.empty()) {
            NodeWeightPair current = pq.top();
            pq.pop();

            char node = current.second;
            int wt = current.first;

            if (vis[node]) continue;
            vis[node] = true;
            totalWeight += wt;

            if (parent.find(node) != parent.end()) {
                mstEdges.push_back(make_tuple(parent[node], node, wt));
            }

            for (auto &neighbor : adj[node]) {
                char adjNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if (!vis[adjNode] && edgeWeight < key[adjNode]) {
                    key[adjNode] = edgeWeight;
                    pq.push({edgeWeight, adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        return totalWeight;
    }
};

int main() {
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    unordered_map<char, vector<pair<char, int>>> adj;
    set<char> nodeSet;

    cout << "Enter edges in format <from> <to> <weight> (e.g. A B 3):\n";
    for (int i = 0; i < E; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        nodeSet.insert(u);
        nodeSet.insert(v);
    }

    vector<char> nodes(nodeSet.begin(), nodeSet.end());
    int V = nodes.size();
    vector<tuple<char, char, int>> mstEdges;

    Solution obj;
    int totalWeight = obj.spanningTree(V, adj, nodes, mstEdges);

    cout << "\nEdges in the MST:\n";
    for (size_t i = 0; i < mstEdges.size(); ++i) {
        char u, v;
        int w;
        tie(u, v, w) = mstEdges[i];
        cout << u << " - " << v << " : " << w << endl;
    }

    cout << "\nTotal weight of MST: " << totalWeight << endl;

    return 0;
}
