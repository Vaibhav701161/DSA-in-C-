/*
Dijkstra’s Shortest Paths (with path reconstruction)

Problem: Given a weighted directed graph (positive weights), source s, compute shortest distances and reconstruct shortest paths.
*/

// dijkstra_reconstruct.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Dijkstra with path reconstruction using parent array.
  - Uses adjacency list: vector<vector<pair<int, long long>>> graph
  - Time: O((V+E) log V)
*/

const long long INF = (1LL<<60);

void dijkstra(int n, const vector<vector<pair<int,long long>>>& g, int src,
    vector<long long>& dist, vector<int>& parent) {

    dist.assign(n, INF);
    parent.assign(n, -1);
    using pli = pair<long long,int>;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &e : g[u]) {
            int v = e.first;
            long long w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

vector<int> reconstruct_path(int t, const vector<int>& parent) {
    vector<int> path;
    for (int cur = t; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 6;
    vector<vector<pair<int,long long>>> g(n);
    auto addEdge = [&](int u, int v, long long w) {
        g[u].push_back({v,w});
    };
    addEdge(0,1,7); addEdge(0,2,9); addEdge(0,5,14);
    addEdge(1,2,10); addEdge(1,3,15);
    addEdge(2,3,11); addEdge(2,5,2);
    addEdge(3,4,6);
    addEdge(4,5,9);

    vector<long long> dist;
    vector<int> parent;
    dijkstra(n, g, 0, dist, parent);

    cout << "Distances from 0:\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": " << (dist[i] >= INF ? -1 : dist[i]) << '\n';
    }

    int target = 4;
    auto path = reconstruct_path(target, parent);
    cout << "Path to " << target << ": ";
    for (int v : path) cout << v << (v==target?'\n':' ');
    return 0;
}
