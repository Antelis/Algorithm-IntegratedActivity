#include <iostream>
#include <vector>
#include <limits.h>
#include "hFiles/distCapMatrix.h"

using namespace std;

void primMST(const vector<vector<int>>& graph, int N) {
    vector<int> parent(N, -1);
    vector<int> key(N, INT_MAX);
    vector<bool> inMST(N, false);

    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < N - 1; ++count) {
        int minKey = INT_MAX, u;
        for (int v = 0; v < N; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < N; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edge   Weight" << endl;
    for (int i = 1; i < N; ++i)
        cout << parent[i] << " - " << i << "    " << graph[i][parent[i]] << endl;
}