#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int node, const vector<vector<int>> &adj, vector<bool> &visited, vector<char> &result) {
        visited[node] = true;
        result.push_back(node + 'A'); // convert index back to char
        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited, result);
            }
        }
    }

public:
    vector<char> dfsOnGraph(int start, const vector<vector<int>> &adj) {
        vector<bool> visited(26, false);
        vector<char> result;
        dfs(start, adj, visited, result);
        return result;
    }
};

void addEdge(vector<vector<int>> &adj, char u, char v) {
    adj[u - 'A'].push_back(v - 'A');
    adj[v - 'A'].push_back(u - 'A'); // undirected
}

void printAns(const vector<char> &ans) {
    for (char ch : ans) {
        cout << ch << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> adj(26); // graph for 26 uppercase letters

    addEdge(adj, 'A', 'B');
    addEdge(adj, 'A', 'I');
    addEdge(adj, 'I', 'E');
    addEdge(adj, 'E', 'F');
    addEdge(adj, 'I', 'F');
    addEdge(adj, 'B', 'F');
    addEdge(adj, 'F', 'G');

    Solution solver;
    vector<char> ans = solver.dfsOnGraph('A' - 'A', adj);
    printAns(ans);

    return 0;
}




// #include <iostream>
// #include <map>
// #include <vector>
// #include <set>
// using namespace std;

// class Solution {
// private:
//     void dfs(char node, map<char, vector<char>> &adj, set<char> &visited, vector<char> &result) {
//         visited.insert(node);
//         result.push_back(node);
//         for (char neighbor : adj[node]) {
//             if (visited.find(neighbor) == visited.end()) {
//                 dfs(neighbor, adj, visited, result);
//             }
//         }
//     }

// public:
//     vector<char> dfsOfGraph(char start, map<char, vector<char>> &adj) {
//         set<char> visited;
//         vector<char> result;
//         dfs(start, adj, visited, result);
//         return result;
//     }
// };

// void addEdge(map<char, vector<char>> &adj, char u, char v) {
//     adj[u].push_back(v);
//     adj[v].push_back(u); // remove this if graph is directed
// }

// void printAns(const vector<char> &ans) {
//     for (char c : ans) {
//         cout << c << " ";
//     }
//     cout << endl;
// }

// int main() {
//     map<char, vector<char>> adj;

//     addEdge(adj, 'A', 'B');
//     addEdge(adj, 'A', 'I');
//     addEdge(adj, 'B', 'F');
//     addEdge(adj, 'I', 'E');
//     addEdge(adj, 'E', 'F');
//     addEdge(adj, 'I', 'F');
//     addEdge(adj, 'F', 'G');




//     Solution obj;
//     vector<char> ans = obj.dfsOfGraph('A', adj);
//     printAns(ans);

//     return 0;
// }
