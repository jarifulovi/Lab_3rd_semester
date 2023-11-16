#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

void initialize(int** &graph, int vertices) {
    graph = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        graph[i] = new int[vertices];
        for (int j = 0; j < vertices; ++j) {
            graph[i][j] = 0;
        }
    }
}

bool bfs(int** rGraph, int vertices, int starting_vertex, int final_vertex, int parent[]) {
    bool* visited = new bool[vertices] {false};
    queue<int> q;
    q.push(starting_vertex);
    visited[starting_vertex] = true;
    parent[starting_vertex] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                parent[v] = u;
                if (v == final_vertex) {
                    delete[] visited;
                    return true;
                }
                q.push(v);
                visited[v] = true;
            }
        }
    }

    delete[] visited;
    return false;
}

int fordFulkerson(int** graph, int vertices, int starting_vertex, int final_vertex) {
    int** rGraph = new int*[vertices];
    for (int u = 0; u < vertices; u++) {
        rGraph[u] = new int[vertices];
        for (int v = 0; v < vertices; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }

    int* parent = new int[vertices];
    int max_flow = 0;

    while (bfs(rGraph, vertices, starting_vertex, final_vertex, parent)) {
        int path_flow = INT_MAX;

        for (int v = final_vertex; v != starting_vertex; ) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
            v = parent[v];
        }

        for (int v = final_vertex; v != starting_vertex; ) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
            v = parent[v];
        }

        max_flow += path_flow;
    }

    // Deallocate memory for rGraph
    for (int u = 0; u < vertices; u++) {
        delete[] rGraph[u];
    }
    delete[] rGraph;
    delete[] parent;

    return max_flow;
}

int main() {
    int vertices;
    freopen("ford_fulkersion_input.txt", "r", stdin);
    cin >> vertices;

    int** graph;
    initialize(graph, vertices);

    int src, des, max_flow;
    while (cin >> src >> des >> max_flow) {
        graph[src - 1][des - 1] = max_flow;
    }

    cout << "The maximum possible flow is " << fordFulkerson(graph, vertices, 0, 5) << "\n";

    // Deallocate memory for graph
    for (int i = 0; i < vertices; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
