#include<bits/stdc++.h>
using namespace std;

void greedyColoring(vector<vector<int>> &adjList){
    int V = adjList.size();
    vector<int> res (V,-1); //to store the result (colors assigned)
    vector<bool> avail(V,false); // to keep track of available colors
    
    // assign the first color to the first vertex
    res[0] = 0 ;

    // assign colors to remaining V-1 vertices
    for( int u = 1; u < V ; u++){

        // Mark colors of adj vertices as unavailable
        for(int adj : adjList[u]){
            if(res[adj] != -1)
                avail[res[adj]] = true;
        }

        // Find the first available color    
        int cr;
        for(cr = 0;cr<V;cr++){
            if(!avail[cr])
                break;
        }

        res[u] = cr; // assign the cound color

        for( int adj : adjList[u])
            if(res[adj] != -1)
                avail[res[adj]] = false;
    }

    // determine the number of colors used
    int maxColor = *max_element(res.begin(),res.end()) + 1;

    cout << "Number of colors used: " << maxColor << endl;

    for(int u=0;u<V;u++){
        cout << "Vertex " << u << " ---> Color " << res[u] << endl;
    }
}

int main(){

    // create a graph as an adjacency list
vector<vector<int>> adjList = {
    {1,2},{0,2,3,4},
    {0,1,3,5},
    {1,2,4,5},
    {1,3,5,6},
    {2,3,4,6},
    {4,5,0}
};
greedyColoring(adjList);

return 0;
}