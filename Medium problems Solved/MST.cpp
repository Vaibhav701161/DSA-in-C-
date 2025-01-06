/*
Minimum Spanning Tree (Kruskal with DSU)

Problem: Given weighted undirected graph, compute MST weight using Kruskal.
*/

// kruskal_mst.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Kruskal's MST using DSU (Union-Find).
  Complexity: O(E log E).
*/

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b) {
        a=find(a); b=find(b);
        if (a==b) return false;
        if (r[a]<r[b]) swap(a,b);
        p[b]=a;
        if (r[a]==r[b]) r[a]++;
        return true;
    }
};

struct Edge {
    int u,v,w;
    bool operator<(const Edge& other) const {
        return w<other.w;
    }
};

int kruskalMST(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int total=0;
    for (auto &e: edges) {
        if (dsu.unite(e.u,e.v)) total+=e.w;
    }
    return total;
}

int main() {
    int n=4;
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };
    cout << "MST weight: " << kruskalMST(n, edges) << '\n';
    return 0;
}
