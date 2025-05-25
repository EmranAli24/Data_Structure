// Slide 9 , page 32


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <climits>  // for INT_MAX

using namespace std;

// Function to find the shortest path using BFS
pair<int, vector<char>> shortestPathChar(
    unordered_map<char, vector<char>>& graph, char start, char end
) {
    queue<pair<int, vector<char>>> q;
    unordered_set<char> visited;
    unordered_map<char, int> min_distances;

    q.push({0, {start}});
    visited.insert(start);
    min_distances[start] = 0;

    while (!q.empty()) {
        pair<int, vector<char>> front = q.front();
        q.pop();
        int distance = front.first;
        vector<char> path = front.second;

        char node = path.back();
        min_distances[node] = distance;

        if (node == end) {
            return {distance, path};
        }

        for (char neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                vector<char> new_path = path;
                new_path.push_back(neighbor);
                q.push({distance + 1, new_path});
            }
        }
    }

    return {INT_MAX, {}};
}

int main() {

    unordered_map<char, vector<char>> graph;
    int edgeCount;
    cout << "Enter number of edges: ";
    cin >> edgeCount;

    cout << "Enter each edge as two characters (e.g., A B):" << endl;
    for (int i = 0; i < edgeCount; ++i) {
        char u, v;
        cin >> u >> v;
        graph[u].push_back(v);
     //   graph[v].push_back(u);  // assuming undirected graph
    }

    char start, end;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter end node: ";
    cin >> end;

    pair<int, vector<char>> result = shortestPathChar(graph, start, end);
    int distance = result.first;
    vector<char> path = result.second;

    if (distance == INT_MAX) {
        cout << "No path found from " << start << " to " << end << "." << endl;
    } else {
        cout << "Shortest distance: " << distance << endl;
        cout << "Path: ";
        for (char node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
