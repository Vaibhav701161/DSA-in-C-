// detect_cycle_directed.cpp
#include <bits/stdc++.h>
using namespace std;

bool dfs(int u,vector<vector<int>>&g,vector<int>&vis,vector<int>&rec){
    vis[u]=1; rec[u]=1;
    for(int v:g[u]){
        if(!vis[v] && dfs(v,g,vis,rec)) return true;
        else if(rec[v]) return true;
    }
    rec[u]=0; return false;
}

bool isCyclic(int V,vector<vector<int>>&edges){
    vector<vector<int>> g(V);
    for(auto&e:edges) g[e[0]].push_back(e[1]);
    vector<int> vis(V,0),rec(V,0);
    for(int i=0;i<V;i++) if(!vis[i] && dfs(i,g,vis,rec)) return true;
    return false;
}

int main(){
    int V=4;
    vector<vector<int>> edges={{0,1},{1,2},{2,0},{2,3}};
    cout<<"Cycle present: "<<isCyclic(V,edges)<<'\n';
}
