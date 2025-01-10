// rotting_oranges.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  BFS rotting process.
  Each minute, rotten oranges infect adjacent fresh ones.
*/

int orangesRotting(vector<vector<int>>& g){
    int m=g.size(),n=g[0].size();
    queue<pair<int,int>> q;
    int fresh=0,minutes=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(g[i][j]==2) q.push({i,j});
            else if(g[i][j]==1) fresh++;
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty() && fresh>0){
        int sz=q.size(); minutes++;
        while(sz--){
            auto [x,y]=q.front();q.pop();
            for(auto&d:dirs){
                int nx=x+d[0],ny=y+d[1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && g[nx][ny]==1){
                    g[nx][ny]=2; fresh--; q.push({nx,ny});
                }
            }
        }
    }
    return fresh==0?minutes:-1;
}

int main(){
    vector<vector<int>> g={{2,1,1},{1,1,0},{0,1,1}};
    cout<<"Minutes to rot: "<<orangesRotting(g)<<'\n';
}
