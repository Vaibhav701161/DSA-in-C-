// kruskal_mst.cpp
#include <bits/stdc++.h>
using namespace std;

struct Edge{int u,v,w;};
struct DSU{
    vector<int> p,sz;
    DSU(int n):p(n),sz(n,1){ iota(p.begin(),p.end(),0);}
    int find(int x){ return x==p[x]?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b];
        return true;
    }
};

int kruskal(int n,vector<Edge>&edges){
    sort(edges.begin(),edges.end(),[](auto&a,auto&b){return a.w<b.w;});
    DSU dsu(n); int mst=0;
    for(auto&e:edges) if(dsu.unite(e.u,e.v)) mst+=e.w;
    return mst;
}

int main(){
    vector<Edge> edges={{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    cout<<"MST weight: "<<kruskal(4,edges)<<'\n';
}
