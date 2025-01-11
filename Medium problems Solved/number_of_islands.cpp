// number_of_islands.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  DFS flood-fill for each land cell.
*/

void dfs(vector<vector<char>>& g,int i,int j){
    if(i<0||j<0||i>=g.size()||j>=g[0].size()||g[i][j]=='0') return;
    g[i][j]='0';
    dfs(g,i+1,j); dfs(g,i-1,j); dfs(g,i,j+1); dfs(g,i,j-1);
}

int numIslands(vector<vector<char>>& g){
    int m=g.size(),n=g[0].size(),count=0;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++){
        if(g[i][j]=='1'){ count++; dfs(g,i,j); }
    }
    return count;
}

int main(){
    vector<vector<char>> g={{'1','1','0','0'},
                            {'1','0','0','1'},
                            {'0','0','1','1'}};
    cout<<"Islands: "<<numIslands(g)<<'\n';
}
