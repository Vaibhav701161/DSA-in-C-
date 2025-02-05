// floyd_warshall.cpp
#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;

void floydWarshall(vector<vector<int>>&dist){
    int n=dist.size();
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dist[i][k]<INF && dist[k][j]<INF)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

int main(){
    vector<vector<int>> dist={
        {0,5,INF,10},
        {INF,0,3,INF},
        {INF,INF,0,1},
        {INF,INF,INF,0}
    };
    floydWarshall(dist);
    cout<<"All Pairs Shortest Path:\n";
    for(auto&r:dist){
        for(int x:r) cout<<(x==INF?999:x)<<' ';
        cout<<'\n';
    }
}
