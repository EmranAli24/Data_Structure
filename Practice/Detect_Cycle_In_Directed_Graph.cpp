/*
Kahn's Algorithm (Topological sorting using BFS).

Intuition:
 ---> Since we know topological sorting is only possible for directed acyclic graphs(DAGs)
if we apply Kahn’s algorithm in a directed cyclic graph(A directed graph that contains a cycle),
it will fail to find the topological sorting(i.e. The final sorting will not contain all the nodes or vertices). 

--> So, finally, we will check the sorting to see if it contains all V vertices or not. 
If the result does not include all V vertices, we can conclude that there is a cycle. 

Note: The intuition is to check the size of the final topological sorting 
if it equals V(no. of vertices or nodes) or not.


******* The Algorithm steps are as follows:

---> First, we will calculate the in-degree of each node and store it in the in-degree array.
 We can iterate through the given adj list, and simply for every node u->v,
we can increase the in-degree of v by 1 in the in-degree array. 

---> Initially, there will be always at least a single node whose indegree is 0.
 So, we will push the node(s) with in-degree 0 into the queue.

--> Then, we will pop a node from the queue including the node in our answer array,
and for all its adjacent nodes, we will decrease the in-degree of that node by one.
For example, if node u that has been popped out from the queue has an edge towards node v(u->v), 
we will decrease indegree[v] by 1.

---> After that, if for any node the in-degree becomes 0, we will push that node again into the queue.

---> We will repeat steps 3 and 4 until the queue is completely empty.
Now, completing the BFS we will get the linear ordering of the nodes in the answer array.

---> Finally, we will check the length of the answer array.
If it equals V(no. of nodes) then the algorithm will return false otherwise it will return true.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		int cnt = 0;
		// o(v + e)
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cnt++;
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (cnt == V) return false;
		return true;
	}
};


int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {2}, {3}, {4, 5}, {2}, {}};
	int V = 6;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);
	if (ans) cout << "True";
	else cout << "Flase";
	cout << endl;
	return 0;
}
