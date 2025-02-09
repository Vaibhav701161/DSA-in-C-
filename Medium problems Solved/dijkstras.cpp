// dijkstra.cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n,int src,vector<vector<pair<int,int>>>&g){
    vector<int> dist(n,1e9);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto &[v,w]:g[u]){
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

int main(){
    int n=5;
    vector<vector<pair<int,int>>> g(n);
    g[0]={{1,10},{4,5}};
    g[1]={{2,1},{4,2}};
    g[2]={{3,4}};
    g[3]={{0,7},{2,6}};
    g[4]={{1,3},{2,9},{3,2}};
    auto dist=dijkstra(n,0,g);
    for(int i=0;i<n;i++) cout<<"Dist["<<i<<"]="<<dist[i]<<'\n';
}
