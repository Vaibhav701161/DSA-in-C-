// bellman_ford.cpp
#include <bits/stdc++.h>
using namespace std;

struct Edge{int u,v,w;};

bool bellmanFord(int V,int src,vector<Edge>&edges,vector<int>&dist){
    dist.assign(V,1e9);
    dist[src]=0;
    for(int i=1;i<V;i++){
        for(auto&e:edges){
            if(dist[e.u]!=1e9 && dist[e.u]+e.w<dist[e.v]){
                dist[e.v]=dist[e.u]+e.w;
            }
        }
    }
    for(auto&e:edges){
        if(dist[e.u]!=1e9 && dist[e.u]+e.w<dist[e.v]) return false;
    }
    return true;
}

int main(){
    int V=5;
    vector<Edge> edges={{0,1,-1},{0,2,4},{1,2,3},{1,3,2},{1,4,2},{3,2,5},{3,1,1},{4,3,-3}};
    vector<int> dist;
    bool noCycle=bellmanFord(V,0,edges,dist);
    cout<<"No negative cycle: "<<noCycle<<'\n';
    if(noCycle){
        for(int i=0;i<V;i++) cout<<"Dist["<<i<<"]="<<dist[i]<<'\n';
    }
}
