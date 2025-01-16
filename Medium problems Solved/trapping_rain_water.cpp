#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int x, y, height;
    bool operator<(const Cell &other) const {
        return height > other.height;
    }
};

int trapRainWater(vector<vector<int>> &heightMap) {
    int m = heightMap.size();
    if (m == 0) return 0;
    int n = heightMap[0].size();
    
    priority_queue<Cell> pq;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        pq.push({i, 0, heightMap[i][0]});
        pq.push({i, n-1, heightMap[i][n-1]});
        visited[i][0] = visited[i][n-1] = true;
    }
    for (int j = 0; j < n; j++) {
        pq.push({0, j, heightMap[0][j]});
        pq.push({m-1, j, heightMap[m-1][j]});
        visited[0][j] = visited[m-1][j] = true;
    }

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int water = 0;

    while (!pq.empty()) {
        Cell cell = pq.top();
        pq.pop();
        for (auto &dir : dirs) {
            int nx = cell.x + dir[0];
            int ny = cell.y + dir[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                visited[nx][ny] = true;
                water += max(0, cell.height - heightMap[nx][ny]);
                pq.push({nx, ny, max(heightMap[nx][ny], cell.height)});
            }
        }
    }
    return water;
}

int main() {
    vector<vector<int>> heightMap = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };
    cout << "Trapped water: " << trapRainWater(heightMap) << endl;
    return 0;
}
