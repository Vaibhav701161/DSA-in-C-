/*
 * DAY 48: Dijkstra's Shortest Path Algorithm
 *
 * Problem Statement:
 * Given a weighted undirected graph with V vertices and a source vertex,
 * find the shortest path from the source to all other vertices.
 *
 * Approach: Use a min-heap (priority queue) with (distance, node).
 * Greedily pick the node with minimum distance and relax its edges.
 *
 * Time Complexity: O((V + E) log V)
 * Space Complexity: O(V + E)
 */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> pii;

vector<int> dijkstra(int src, int V, vector<vector<pii>>& adj) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [weight, v] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);
    adj[0].push_back({10, 1}); adj[1].push_back({10, 0});
    adj[0].push_back({3,  2}); adj[2].push_back({3,  0});
    adj[1].push_back({1,  3}); adj[3].push_back({1,  1});
    adj[2].push_back({4,  1}); adj[1].push_back({4,  2});
    adj[2].push_back({8,  3}); adj[3].push_back({8,  2});
    adj[3].push_back({2,  4}); adj[4].push_back({2,  3});

    vector<int> dist = dijkstra(0, V, adj);
    cout << "Shortest distances from vertex 0:" << endl;
    for (int i = 0; i < V; i++)
        cout << "  To " << i << ": " << dist[i] << endl;
    return 0;
}
