#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution{
    public:
        vector<char> bfsOfGraph(int V, vector<vector<int>> & graph){
            vector<int> visited(V,0);
            vector<char> bfsresult;
            queue<int> q;

            int startNode = 0; // 'A' is node 0;
            visited[startNode] = 1;
            q.push(startNode);

         while (!q.empty()) 
         {
            int  curr = q.front();
            q.pop();
            bfsresult.push_back(curr + 'A');// convert index to alphabet.

            for(int neighbour : graph[curr]){
                if(!visited[neighbour]){
                    visited[neighbour] = 1 ;
                    q.push(neighbour);
                }
            }
         }

         return bfsresult ;
         
        }
};

// add edge between two nodes
void addEdge(vector<vector<int>>& graph, char u,char v){

    int uIndex = u - 'A';
    int vIndex = v - 'A';
    graph[uIndex].push_back(vIndex);
    graph[vIndex].push_back(uIndex);
}

//  print the result as characters
void printResult(const vector<char> &result){
    for( char ch : result)
        cout << ch << " ";
    cout << endl;
}

int main(){

/*  Since highest character is 'I' (index 8), we need 9 nodes (0 to 8)
    int total_nodes = 9; 
    */ 

 int total_nodes = 9 ;
  //  cout << "Enter total number of nodes: " << endl ;
  //  cin >> total_nodes ;

    vector<vector<int>> graph(total_nodes); 

    // creating the graph

    addEdge(graph,'A','B');
    addEdge(graph,'A','I');
    addEdge(graph,'B','F');
    addEdge(graph,'I','E');
    addEdge(graph,'I','F');
    addEdge(graph,'E','F');
    addEdge(graph,'F','G');

    Solution solver ;

    vector<char> bfs = solver.bfsOfGraph(total_nodes,graph);
    printResult(bfs);
    return 0;
 
}


