#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <climits>

using namespace std;

const int MAX_VERTICES = 20; 
const int INF = INT_MAX;

string name[MAX_VERTICES];
int n;
int w[MAX_VERTICES][MAX_VERTICES];
int nextVertex[MAX_VERTICES][MAX_VERTICES];

void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (i == j)
                w[i][j] = 0;
            else
                w[i][j] = INF;
        }
    }
}

void readInput() {
    string u, v;
    int weight;
    int edge;
   
    n = 0;
    cin >> edge;
    while (cin >> u) {
      
        if (u == "END")
            break;

      
        bool isNewVertexU = true;
        for (int i = 0; i < n; i++) {
            if (name[i] == u) {
                isNewVertexU = false;
                break;
            }
        }

       
        if (isNewVertexU) {
            name[n] = u;
            n++;
           
        }

        cin >> v;

        
        bool isNewVertexV = true;
        for (int i = 0; i < n; i++) {
            if (name[i] == v) {
                isNewVertexV = false;
                break;
            }
        }

      
        if (isNewVertexV) {
            name[n] = v;
            n++;
           
        }

        cin >> weight;

       
        int uIndex, vIndex;
        for (int i = 0; i < n; i++) {
            if (name[i] == u)
                uIndex = i;
            if (name[i] == v)
                vIndex = i;
        }

        w[uIndex][vIndex] = weight;
    }
   
}
void printShortestPaths(int nextVertex[MAX_VERTICES][MAX_VERTICES]) {
    cout << "Shortest paths between every pair of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << "From " << name[i] << " to " << name[j] << ": ";

                if (w[i][j] == INF) {
                    cout << "No path exists.";
                } 
                else {
                    cout << name[i];
                    int intermediate = i;

                    while (intermediate != j) {
                        intermediate = nextVertex[intermediate][j];
                        cout << " -> " << name[intermediate];
                    }
                    cout << ", Distance: " << w[i][j];
                }

                cout << endl;
            }
        }
    }
}

void floydWarshall() {
    int i, j, k;
   

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nextVertex[i][j] = j;
        }
    }
    
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (w[i][k] != INF && w[k][j] != INF &&
                    w[i][k] + w[k][j] < w[i][j]) {
                    w[i][j] = w[i][k] + w[k][j];
                    nextVertex[i][j] = nextVertex[i][k];
                }
            }
        }
    }
    printShortestPaths(nextVertex);
    
    
}

int main() {
    initializeGraph();
    freopen("input.txt", "r", stdin);

    readInput();
    floydWarshall();

    printf("Enter two vertices : \n");
    int a,b;
    cin >> a >> b;
    cout << "From " << name[a] << " to " << name[b] << ": ";
    cout << name[a];
    int intermediate = a;

    while (intermediate != b) {
            intermediate = nextVertex[intermediate][b];
            cout << " -> " << name[intermediate];
            }
    cout << ", Distance: ";
    if(w[a][b]==INF) cout << "No path exist\n";
    else cout << w[a][b] << "\n";

    return 0;
}
