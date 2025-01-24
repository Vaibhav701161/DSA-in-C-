// 48_articulation_points.cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> tin, low;
vector<bool> visited, isAP;
int timer;

void dfs(int v, int p=-1) {
    visited[v]=true;
    tin[v]=low[v]=++timer;
    int children=0;
    for (int to: g[v]) {
        if (to==p) continue;
        if (visited[to]) {
            low[v]=min(low[v],tin[to]);
        } else {
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if (low[to]>=tin[v] && p!=-1) isAP[v]=true;
            ++children;
        }
    }
    if (p==-1 && children>1) isAP[v]=true;
}

int main() {
    int n=5;
    g.assign(n,{});
    g[0]={1,2};
    g[1]={0,2};
    g[2]={0,1,3,4};
    g[3]={2,4};
    g[4]={2,3};
    tin.assign(n,-1); low.assign(n,-1);
    visited.assign(n,false);
    isAP.assign(n,false);
    timer=0;
    for(int i=0;i<n;++i) if(!visited[i]) dfs(i);
    cout<<"Articulation points: ";
    for(int i=0;i<n;++i) if(isAP[i]) cout<<i<<" ";
    cout<<"\n";
    return 0;
}
    printSolution(solutions);
    return 0;
}
    return node->value;
}
        updateFreq(node);
    }
}   int n = 8;
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);
    cout << "Total solutions: " << solutions.size() << endl;
    printSolution(solutions);
    return 0;
}