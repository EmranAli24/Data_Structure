/*

Dijkstra's Shortest Path algorithm and Bellman-Ford algorithm are single-source 
shortest path algorithms where we are given a single source node and 
are asked to find out the shortest path to every other node from that given source.
But in the Floyd Warshall algorithm, we need to figure out the shortest distance
from each node to every other node.

Basically, the Floyd Warshall algorithm is a multi-source shortest path algorithm
and it helps to detect negative cycles as well. The shortest path between node u and v 
necessarily means the path(from u to v) for which the sum of the edge weights is minimum.

In Floyd Warshall's algorithm, we need to check every possible path going via each possible node. 
And after checking every possible path, we will figure out
the shortest path(a kind of brute force approach to find the shortest path).


In order to apply this algorithm to an undirected graph, 
we just need to convert the undirected edges into directed edges like the following:

U ----- V (weight)  : u ----> v , v ----> u 


Negative Cycle: A cycle is called a negative cycle if the sum of all its weights becomes negative.

So, if we find that the cost of reaching any node from itself is less than 0, 
we can conclude that the graph has a negative cycle.

If the graph has a negative cycle: We cannot apply Dijkstra’s algorithm to the graph
which contains a negative cycle. It will give TLE error in that case.

If the graph does not contain a negative cycle: In this case, we will apply Dijkstra’s algorithm
for every possible node to make it work like a multi-source shortest path algorithm like Floyd Warshall.

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == -1) {
					matrix[i][j] = 1e9;
				}
				if (i == j) matrix[i][j] = 0;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][k] + matrix[k][j]);
				}
			}
		}




		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1e9) {
					matrix[i][j] = -1;
				}
			}
		}
	}
};


int main() {

	int V = 4;
	vector<vector<int>> matrix(V, vector<int>(V, -1));
	matrix[0][1] = 2;
	matrix[1][0] = 1;
	matrix[1][2] = 3;
	matrix[3][0] = 3;
	matrix[3][1] = 5;
	matrix[3][2] = 4;

	Solution obj;
	obj.shortest_distance(matrix);

	for (auto row : matrix) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}

	return 0;
}