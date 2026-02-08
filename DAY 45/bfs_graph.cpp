/*
 * DAY 45: Graph BFS Traversal
 *
 * Problem Statement:
 * Given an undirected graph represented as an adjacency list and a source node,
 * perform Breadth-First Search (BFS) and print all reachable nodes.
 *
 * Approach: Use a queue and a visited array. Start from source, enqueue all
 * unvisited neighbors, mark them visited, repeat until queue is empty.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int src, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[src] = true;
    q.push(src);
    cout << "BFS from " << src << ": ";
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};
    bfs(0, adj, V);
    return 0;
}
