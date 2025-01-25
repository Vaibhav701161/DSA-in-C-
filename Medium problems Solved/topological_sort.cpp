// 50_topological_sort.cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<vector<int>>& adj) {
    vector<int> indeg(V,0);
    for(int u=0;u<V;++u) for(int v: adj[u]) indeg[v]++;
    queue<int> q;
    for(int i=0;i<V;++i) if(indeg[i]==0) q.push(i);
    vector<int> order;
    while(!q.empty()) {
        int u=q.front();q.pop();
        order.push_back(u);
        for(int v: adj[u]) if(--indeg[v]==0) q.push(v);
    }
    return order;
}

int main() {
    int V=6;
    vector<vector<int>> adj(V);
    adj[5]={2,0};
    adj[4]={0,1};
    adj[2]={3};
    adj[3]={1};
    auto order=topoSort(V,adj);
    cout<<"Topological order: ";
    for(int x: order) cout<<x<<" ";
    cout<<"\n";
    return 0;
}
