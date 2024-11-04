#ifndef PRIMMST
#define PRIMMST

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void primMST(const vector<vector<int>>& graph, int N) {
    vector<int> parent(N, -1);
    vector<int> key(N, INT_MAX);
    vector<bool> inMST(N, false);

    key[0] = 0; // Start from the first vertex
    parent[0] = -1; // Set first node as the root of the MST

    for (int count = 0; count < N - 1; ++count) {
        int minKey = INT_MAX, u = -1;

        // Find the vertex with the minimum key value
        for (int v = 0; v < N; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        if (u == -1) break; // If no vertex was found (graph is disconnected), break

        inMST[u] = true; // Include vertex u in MST

        // Update key values of the adjacent vertices
        for (int v = 0; v < N; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the edges of the MST
    cout << "Edge\tWeight" << endl;
    for (int i = 1; i < N; ++i) {
        if (parent[i] != -1) { // If the parent is valid
            cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
        }
    }
}

#endif