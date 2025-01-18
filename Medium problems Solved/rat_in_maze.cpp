// 44_rat_in_maze.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Classic backtracking with marking visited.
  Moves: D, L, R, U
*/

int N;
vector<string> paths;
vector<vector<int>> maze;
vector<vector<bool>> vis;

void solve(int r, int c, string path) {
    if (r == N-1 && c == N-1) {
        paths.push_back(path);
        return;
    }
    string dir = "DLRU";
    int dr[] = {1,0,0,-1};
    int dc[] = {0,-1,1,0};
    for (int k=0;k<4;++k) {
        int nr = r+dr[k], nc = c+dc[k];
        if (nr>=0 && nc>=0 && nr<N && nc<N && maze[nr][nc] && !vis[nr][nc]) {
            vis[nr][nc]=true;
            solve(nr,nc,path+dir[k]);
            vis[nr][nc]=false;
        }
    }
}

int main() {
    maze = {{1,0,0,0},
            {1,1,0,1},
            {1,1,0,0},
            {0,1,1,1}};
    N = maze.size();
    vis.assign(N, vector<bool>(N,false));
    if (maze[0][0]==0) { cout<<"No paths\n"; return 0; }
    vis[0][0]=true;
    solve(0,0,"");
    cout << "All paths:\n";
    for (auto &p: paths) cout << p << '\n';
    return 0;
}
