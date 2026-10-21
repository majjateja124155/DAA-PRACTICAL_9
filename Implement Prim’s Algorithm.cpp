
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void primMST(int V, vector<vector<int>>& graph) {
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);

    key[0] = 0;

    for (int count = 0; count < V; count++) {
        int u = -1;
        int minKey = INT_MAX;

        // Find the minimum key vertex not in MST
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        // Check whether the graph is connected
        if (u == -1) {
            cout << "Graph is disconnected. MST cannot be formed.\n";
            return;
        }

        inMST[u] = true;

        // Update keys of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                !inMST[v] &&
                graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;

    cout << "\nMinimum Spanning Tree (Prim's Algorithm):\n";
    cout << "Edge \tWeight\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << '\n';
        totalWeight += graph[i][parent[i]];
    }

    cout << "Total MST Weight: " << totalWeight << '\n';
}

int main() {
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    if (V <= 0) {
        cout << "Invalid number of vertices.\n";
        return 0;
    }

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (0 for no edge):\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(V, graph);

    return 0;
}
