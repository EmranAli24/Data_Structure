
// slide 9 , page : 68
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        // Create a priority queue for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node. 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialising distTo list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> distTo(V, INT_MAX);

        // Source initialised with dist=0.
        distTo[S] = 0;
        pq.push({0, S});

        // Now, pop the minimum distance node first from the min-heap
        // and traverse for all its adjacent nodes.
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            // Check for all adjacent nodes of the popped out
            // element whether the prev dist is larger than current or not.
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
    
                    // If current distance is smaller,
                    // push it into the queue.
                    pq.push({dis + w, v});
                }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return distTo;
    }
};

int main()
{
    // Driver code.
    int V = 9, E = 28, S = 0;
    vector<vector<int>> adj[V];
   // vector<vector<int>> edges;
    vector<int> v1{1, 4}, v2{7, 8}, v3{0,4}, v4{7, 11}, v5{2, 8},v6{1,8}, v7{8, 2}
    ,v8{3,7},v9{5,4},v10{2,7},v11{5,14},v12{4,9},
    v13{3,9},v14{5,10},v15{4,10},v16{3,14},v17{2,4},v18{6,2},v19{5,2},v20{8,6},v21{7,1},
    v22{6,1},v23{8,7},v24{1,11},v25{0,8},v26{2,2},v27{6,6},v28{7,7};//

    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[1].push_back(v5);
    adj[2].push_back(v6);
    adj[2].push_back(v7);
    adj[2].push_back(v8);
    adj[2].push_back(v9);
    adj[3].push_back(v10);
    adj[3].push_back(v11);
    adj[3].push_back(v12);
    adj[4].push_back(v13);
    adj[4].push_back(v14);
    adj[5].push_back(v15);
    adj[5].push_back(v16);
    adj[5].push_back(v17);
    adj[5].push_back(v18);
    adj[6].push_back(v19);
    adj[6].push_back(v20);
    adj[6].push_back(v21);
    adj[7].push_back(v22);
    adj[7].push_back(v23);
    adj[7].push_back(v24);
    adj[7].push_back(v25);
    adj[8].push_back(v26);
    adj[8].push_back(v27);
    adj[8].push_back(v28);



    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}