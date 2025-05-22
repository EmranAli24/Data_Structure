/*
--> Here’s the algorithm to detect cycles in an undirected graph:

1. Perform a depth-first search (DFS) traversal starting from each unvisited vertex
2. During DFS traversal, mark current vertex as visited
3. For each unvisited neighbor from the current vertex:
   ~If the neighbor vertex is not visited, perform DFS on this vertex
   ~If the neighbor vertex is already visited, it means there is a cycle
*/


#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Function to perform depth-first search to detect cycles in an undirected graph
bool dfs(int vertex, vector<vector<pair<int, int>>>& graph, unordered_set<int>& visited, int parent) {
  // Mark the current node as visited
  visited.insert(vertex);

  // Traverse through all the neighbors of the current node
  for (const auto& neighbor : graph[vertex]) {
    // If the neighbor is not visited yet
    if (visited.find(neighbor.first) == visited.end()) {
      // Recursively call DFS on the neighbor
      if (dfs(neighbor.first, graph, visited, vertex)) {
        return true;
      }
    }
    // If the neighbor is visited and not the parent of the current node
    else if (neighbor.first != parent) {
      // There is a cycle detected
      return true;
    }
  }

  // No cycle detected for the current node
  return false;
}

// Function to detect if there is a cycle in the graph
bool detect_cycle(vector<vector<pair<int, int>>>& graph) {
  // Initialize a set to keep track of visited nodes
  unordered_set<int> visited;

  // Traverse through all the nodes in the graph
  for (int node = 0; node < graph.size(); node++) {
    // If the node is not visited yet
    if (visited.find(node) == visited.end()) {
      // Call the DFS function on the node
      if (dfs(node, graph, visited, -1)) {
        return true;
      }
    }
  }

  // No cycle detected in the graph
  return false;
}


int main() {
  // Sample graph to test cycle detection
  vector<vector<pair<int, int>>> graph1 = {
      {{1, 0}, {2, 0}},
      {{0, 0}, {2, 0}, {3, 0}},
      {{0, 0}, {1, 0}, {4, 0}, {5, 0}},
      {{1, 0}},
      {{2, 0}},
      {{2, 0}}
  };

  if (detect_cycle(graph1)) {
    cout << "Graph 1 has a cycle!" << endl;
  } else {
    cout << "Graph 1 does not have a cycle!" << endl;
  }

  // Sample graph to test cycle detection
  vector<vector<pair<int, int>>> graph2 = {
      {{1, 0}, {2, 0}},
      {{0, 0}, {3, 0}},
      {{0, 0}, {4, 0}, {5, 0}},
      {{1, 0}},
      {{2, 0}},
      {{2, 0}}
  };

  if (detect_cycle(graph2)) {
    cout << "Graph 2 has a cycle!" << endl;
  } else {
    cout << "Graph 2 does not have a cycle!" << endl;
  }

  return 0;
}