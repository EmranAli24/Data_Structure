#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Function to check Euler's formula for planarity (for connected simple graphs)
bool isPlanarByEuler(int V, int E) {
    // For planar graphs: E <= 3V - 6 (when V >= 3)
    if (V < 3) return true; // trivial graphs are planar
    return E <= 3 * V - 6;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, int>> edges(E);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    if (isPlanarByEuler(V, E))
        cout << "The graph may be planar (passes Euler's formula test)." << endl;
    else
        cout << "The graph is NOT planar (fails Euler's formula test)." << endl;

    return 0;
}
