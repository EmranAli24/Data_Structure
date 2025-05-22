/*

Here’s an algorithm to detect cycles in a directed graph using the white, gray, and black (0, 1, 2) 
marking technique:

1. Initialize all vertices in the graph as white (0).
2. Perform a depth-first search (DFS) traversal starting from vertices still marked as white.
3. During the DFS traversal, mark each vertex as follows:
        --> When a vertex is first visited, mark it as gray (1).
        --> When the DFS has finished exploring all the vertices
           reachable from the current vertex, mark it as black (2).
4. If, during the DFS traversal, a gray vertex is encountered,
   it means a cycle has been detected.

*/

#include <iostream>
#include <unordered_map>
#include <vector>

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

bool dfs(std::string vertex, std::unordered_map<std::string, std::vector<std::string>>& graph, std::unordered_map<std::string, int>& color_of_vertex) {
  // Mark the current vertex as gray (in progress)
  color_of_vertex[vertex] = GRAY;

  // Check all neighboring vertices
  for (const auto& neighbor : graph[vertex]) {
    if (color_of_vertex[neighbor] == WHITE) {
      // If the neighbor hasn't been visited, explore it
      if (dfs(neighbor, graph, color_of_vertex)) {
        return true;  // Cycle detected in subtree
      }
    } else if (color_of_vertex[neighbor] == GRAY) {
      // If we find a gray neighbor, we've found a cycle
      return true;
    }
  }

  // Mark the vertex as black
  // This means that all vertices reachable from this node
  // are fully explored before backtracking
  color_of_vertex[vertex] = BLACK;

  // No cycle found in this subtree
  return false;
}

bool detect_cycle(std::unordered_map<std::string, std::vector<std::string>>& graph) {
  // Initialize all vertices as white (not visited)
  std::unordered_map<std::string, int> color_of_vertex;
  for (const auto& pair : graph) {
    color_of_vertex[pair.first] = WHITE;
  }

  // Check each vertex in the graph
  for (const auto& pair : graph) {
    // If the vertex hasn't been visited, start a DFS
    if (color_of_vertex[pair.first] == WHITE) {
      if (dfs(pair.first, graph, color_of_vertex)) {
        return true;  // Cycle detected
      }
    }
  }

  // If we've checked all vertices and found no cycles
  return false;
}

int main() {
  // Sample graph to test cycle detection
  std::unordered_map<std::string, std::vector<std::string>> graph1 = {
    {"A", {"C"}},
    {"B", {"A", "D"}},
    {"C", {"B", "D"}},
    {"D", {}}
  };

  if (detect_cycle(graph1)) {
    std::cout << "Graph 1 has a cycle!" << std::endl;
  } else {
    std::cout << "Graph 1 does not have a cycle!" << std::endl;
  }

  // Sample graph to test cycle detection
  std::unordered_map<std::string, std::vector<std::string>> graph2 = {
    {"A", {"B", "C"}},
    {"B", {"D"}},
    {"C", {"B", "D"}},
    {"D", {}}
  };

  if (detect_cycle(graph2)) {
    std::cout << "Graph 2 has a cycle!" << std::endl;
  } else {
    std::cout << "Graph 2 does not have a cycle!" << std::endl;
  }

  return 0;
}