// C++ program for implementation of Ford Fulkerson
// algorithm
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
#define SIZE 50
int vertices;
bool bfs(int rGraph[SIZE][SIZE], int start_vertex, int final_vertex, int parent[])
{
	bool visited[SIZE];
	memset(visited, 0, sizeof(visited));

	queue<int> q;
	q.push(start_vertex);
	visited[start_vertex] = true;
	parent[start_vertex] = -1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < vertices; v++) {
			if (visited[v] == false && rGraph[u][v] > 0) {
				parent[v] = u;
				if (v == final_vertex) {
					return true;
				}
				q.push(v);
				visited[v] = true;
			}
		}
	}
	return false;
}


int fordFulkerson(int graph[SIZE][SIZE], int start_vertex, int final_vertex)
{
	int u, v;

	
	int rGraph[SIZE][SIZE]; 
	for (u = 0; u < SIZE; u++)
		for (v = 0; v < SIZE; v++)
			rGraph[u][v] = graph[u][v];

	int parent[SIZE]; 

	int max_flow = 0; 

	
	while (bfs(rGraph, start_vertex, final_vertex, parent)) {
		
		int path_flow = INT_MAX;
		for (v = final_vertex; v != start_vertex; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}
        cout << "Augmenting path : ";
		for (v = final_vertex; v != start_vertex; v = parent[v]) {
            cout << v << " <- ";
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
        cout << start_vertex;
        cout << " and the bottleneck capacity : " << path_flow << "\n";
		
		max_flow += path_flow;
	}

	return max_flow;
}
int main()
{   
    freopen("ford_fulkerson_input.txt","r",stdin);
	int graph[SIZE][SIZE] = {{0}};
    int src,des,max_flow;
    cin >> vertices;
    while(cin >> src >> des >> max_flow){
        graph[src][des] = max_flow;
    }
	cout << "The maximum possible flow is "
		<< fordFulkerson(graph, 0, vertices-1);
	return 0;
}
