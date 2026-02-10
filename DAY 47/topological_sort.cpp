/*
 * DAY 47: Topological Sort (Kahn's Algorithm - BFS)
 *
 * Problem Statement:
 * Given a Directed Acyclic Graph (DAG) with V vertices and E edges,
 * find a topological ordering of vertices.
 *
 * Approach: Kahn's Algorithm using in-degree and BFS.
 * 1. Compute in-degree for all vertices.
 * 2. Enqueue all vertices with in-degree 0.
 * 3. Process queue: for each vertex, reduce neighbor in-degrees; enqueue if 0.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; u++)
        for (int v : adj[u]) inDegree[v]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (inDegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);
        for (int v : adj[node])
            if (--inDegree[v] == 0) q.push(v);
    }
    return order;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    vector<int> result = topoSort(V, adj);
    cout << "Topological Order: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}
