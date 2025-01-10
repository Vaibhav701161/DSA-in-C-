// course_schedule.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Course Schedule: cycle detection using BFS (Kahn’s algorithm).
*/

bool canFinish(int n, vector<vector<int>>& pre) {
    vector<int> indeg(n,0);
    vector<vector<int>> g(n);
    for(auto&p:pre){ g[p[1]].push_back(p[0]); indeg[p[0]]++; }
    queue<int> q;
    for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i);
    int cnt=0;
    while(!q.empty()){
        int u=q.front();q.pop();cnt++;
        for(int v:g[u]){
            if(--indeg[v]==0) q.push(v);
        }
    }
    return cnt==n;
}

int main(){
    int n=2;
    vector<vector<int>> pre={{1,0}};
    cout<<"Can finish: "<<canFinish(n,pre)<<'\n';
}
