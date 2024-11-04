#ifndef MAXFLOW
#define MAXFLOW

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// Function to perform a BFS to find an augmenting path
bool bfs(const vector<vector<int>>& residual, int source, int sink, vector<int>& parent) {
    int n = residual.size();
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            // If node v is not visited and there's capacity left in the residual graph
            if (!visited[v] && residual[u][v] > 0) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;

                // Stop BFS if we reached the sink node
                if (v == sink) return true;
            }
        }
    }
    return false; // No augmenting path found
}

// Function to calculate maximum flow using Ford-Fulkerson with Edmonds-Karp
int fordFulkerson(const vector<vector<int>>& capacity, int N) {
    int source = 0;
    int sink = N - 1;
    vector<vector<int>> residual = capacity; // Create residual graph
    vector<int> parent(N);                   // Stores the path

    int maxFlow = 0; // Initialize max flow to zero

    // Augment the flow while there is a path from source to sink
    while (bfs(residual, source, sink, parent)) {
        // Find the maximum flow through the path found
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }

        // Update residual capacities of the edges and reverse edges along the path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }

        maxFlow += pathFlow; // Add path flow to overall flow
    }

    return maxFlow;
}


#endif