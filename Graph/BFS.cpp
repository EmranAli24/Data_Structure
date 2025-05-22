#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<vector<int>>& graph) {
        vector<int> visited(V, 0);  // Visited array
        vector<int> bfsResult;      // Store the BFS result
        queue<int> q;

        int startNode = 1;          // 1-based indexing
        visited[startNode] = 1;
        q.push(startNode);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            bfsResult.push_back(current);

            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }

        return bfsResult;
    }
};

// Add edge between two nodes
void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);  // Since the graph is undirected
}

// Print the result vector
void printResult(const vector<int>& result) {
    for (int node : result)
        cout << node << " ";
    cout << endl;
}

int main() {
    int totalNodes = 5; // Nodes are 1-based: 1 to 5
    vector<vector<int>> graph(totalNodes + 1); // +1 to make it 1-based

    // Creating the graph
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    Solution solver;
    vector<int> bfs = solver.bfsOfGraph(totalNodes + 1, graph);

    printResult(bfs);

    return 0;
}
