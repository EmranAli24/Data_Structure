#include<bits/stdc++.h>
using namespace std;


class Solution{

    public:

    vector<int> bfsOfGraph(int V, vector<vector<int>> &graph ){
        vector<int> visited(V,0);
        vector<int> bfsResult;
        queue<int> q;

        int startNode = 2;
        visited[startNode] = 1 ;
        q.push(startNode);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            bfsResult.push_back(curr);

            for(int neighbour : graph[curr]){
                if(!visited[neighbour]){
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }

        return bfsResult;


    }

};

void addEdge(vector<vector<int>> &graph,int u,int v){
    graph[u].push_back(v);
}

void printResult(const vector<int> & result){
    for( int node: result) 
        cout << node << " ";

    cout << endl;
}

int main(){
    int numberOfNodes = 4;
    vector<vector<int>> graph(4);

    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,2,0);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,3);

    Solution solver;

    vector<int> bfsResult = solver.bfsOfGraph(numberOfNodes,graph);
    printResult(bfsResult);

    return 0;
}