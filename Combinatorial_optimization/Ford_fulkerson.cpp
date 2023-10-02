#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
#define V 6

bool bfs(int rGraph[V][V], int s, int t, int parent[]){
	bool visited[V] = {false};

	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < V; v++) {
			if (visited[v] == false && rGraph[u][v]>0) {
                parent[v] = u;
				if (v == t) {
					return true;
				}
				q.push(v);
				visited[v] = true;
			}
		}
	}
	return false;
}
int fordFulkerson(int graph[V][V], int s, int t)
{
	int u, v;

	int rGraph[V][V];

	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];

	int parent[V]; 

	int max_flow = 0;

	while (bfs(rGraph, s, t, parent)) {
		
		int path_flow = INT_MAX;
		for (v = t; v != s;) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
            v = parent[v];
		}

		for (v = t; v != s; ) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
            v = parent[v];
		}

		max_flow += path_flow;
	}
	return max_flow;
}
int main()
{
	int graph[V][V]
		= { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
			{ 0, 4, 0, 0, 14, 0 }, { 0, 0, 9, 0, 0, 20 },
			{ 0, 0, 0, 7, 0, 4 }, { 0, 0, 0, 0, 0, 0 } };

	cout << "The maximum possible flow is "<< fordFulkerson(graph, 0, 5) << "\n";

	return 0;
}