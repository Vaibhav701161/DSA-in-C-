/*
 * DAY 46: Graph DFS Traversal
 *
 * Problem Statement:
 * Given a directed graph as an adjacency list and a source node,
 * perform Depth-First Search (DFS) and print all reachable nodes.
 *
 * Approach: Recursive DFS. Mark node as visited, print it, then recursively
 * visit all unvisited neighbors.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {3, 4};
    adj[2] = {5};
    adj[3] = {};
    adj[4] = {};
    adj[5] = {};

    vector<bool> visited(V, false);
    cout << "DFS from 0: ";
    dfs(0, adj, visited);
    cout << endl;
    return 0;
}
