#include <bits/stdc++.h>
using namespace std;

class DSU {
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;

public:
    DSU(const vector<string>& places) {
        for (const string& place : places) {
            parent[place] = "";
            rank[place] = 1;
        }
    }

    string find(const string& place) {
        if (parent[place] == "")
            return place;

        return parent[place] = find(parent[place]);
    }

    void unite(const string& x, const string& y) {
        string s1 = find(x);
        string s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            } else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            } else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class Graph {
    vector<tuple<int, string, string>> edgelist;
    unordered_set<string> vertices;

public:
    void addEdge(const string& x, const string& y, int w) {
        edgelist.push_back({w, x, y});
        vertices.insert(x);
        vertices.insert(y);
    }

    void kruskals_mst() {
        sort(edgelist.begin(), edgelist.end());

        DSU s(vector<string>(vertices.begin(), vertices.end()));
        int ans = 0;
        cout << "Following are the edges in the constructed MST" << endl;
        for (const auto& edge : edgelist) {
            int w = get<0>(edge);
            string x = get<1>(edge);
            string y = get<2>(edge);

            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans;
    }
};

int main() {
    Graph g;
    // Add edges to the graph with string identifiers
    g.addEdge("a", "b", 4);
    g.addEdge("a", "h", 8);
    g.addEdge("b", "c", 8);
    g.addEdge("b", "h", 11);
    g.addEdge("c", "d", 7);
    g.addEdge("c", "i", 2);
    g.addEdge("c", "f", 4);
    g.addEdge("d", "e", 9);
    g.addEdge("d", "f", 14);
    g.addEdge("e", "f", 10);
    g.addEdge("f", "g", 2);
    g.addEdge("g", "h", 1);
    g.addEdge("g", "i", 6);
    g.addEdge("h", "i", 7);


    // ... (add more edges as needed)

    // Find and print the MST
    g.kruskals_mst();

    return 0;
}
