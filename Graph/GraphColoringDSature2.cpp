/// when we denote the node with alphabet. then --
#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <map>
using namespace std;

// Function to add edge between two vertices.
void addEdgeBetween(vector<int> graph[], int a, int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}

// For storing information related to vertices.
class vertexInfo
{
public:
    int sat;     // Saturation degree
    int deg;     // Degree
    int vertex;  // Vertex index
};

// Custom comparator for vertex priority queue.
struct maxSat
{
    bool operator()(const vertexInfo &lhs, const vertexInfo &rhs) const
    {
        return tie(lhs.sat, lhs.deg, lhs.vertex) > tie(rhs.sat, rhs.deg, rhs.vertex);
    }
};

// Function to print colors assigned to each character vertex.
void printColor(vector<int> &color, map<int, char> &indexToChar)
{
    for (int i = 0; i < color.size(); i++)
    {
        cout << "The Color of the vertex " << indexToChar[i] << " is " << color[i] << endl;
    }
}

// DSatur Algorithm
int DSatur(vector<int> graph[], int V, map<int, char> &indexToChar)
{
    vector<bool> use(V, false);
    vector<int> color(V, -1), d(V);
    vector<set<int>> adjCols(V);
    set<vertexInfo, maxSat> Q;

    for (int u = 0; u < V; u++)
    {
        d[u] = graph[u].size();
        Q.emplace(vertexInfo{0, d[u], u});
    }

    while (!Q.empty())
    {
        auto maxPtr = Q.begin();
        int u = maxPtr->vertex;
        Q.erase(maxPtr);

        for (int v : graph[u])
            if (color[v] != -1)
                use[color[v]] = true;

        int i = 0;
        while (i != use.size() && use[i]) i++;
        for (int v : graph[u])
            if (color[v] != -1)
                use[color[v]] = false;

        color[u] = i;

        for (int v : graph[u])
        {
            if (color[v] == -1)
            {
                Q.erase(vertexInfo{(int)adjCols[v].size(), d[v], v});
                adjCols[v].insert(i);
                d[v]--;
                Q.emplace(vertexInfo{(int)adjCols[v].size(), d[v], v});
            }
        }
    }

    printColor(color, indexToChar);

    set<int> uniqueColors(color.begin(), color.end());
    cout << "The Chromatic number is : ";
    return uniqueColors.size();
}

// Main input and mapping handler
int getChromaticNumber()
{
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    map<char, int> charToIndex;
    map<int, char> indexToChar;
    vector<pair<char, char>> edges;
    set<char> vertices;

    cout << "Enter each edge as two capital letters (e.g., A B):\n";
    for (int i = 0; i < E; i++)
    {
        char u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        vertices.insert(u);
        vertices.insert(v);
    }

    int idx = 0;
    for (char ch : vertices)
    {
        charToIndex[ch] = idx;
        indexToChar[idx] = ch;
        idx++;
    }

    int V = vertices.size();
    vector<int> graph[V];
    for (auto &edge : edges)
    {
        int a = charToIndex[edge.first];
        int b = charToIndex[edge.second];
        addEdgeBetween(graph, a, b);
    }

    return DSatur(graph, V, indexToChar);
}

int main()
{
    cout << getChromaticNumber() << endl;
    return 0;
}
