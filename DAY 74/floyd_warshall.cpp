/*
 * DAY 74: Floyd-Warshall All-Pairs Shortest Path
 *
 * Problem Statement:
 * Given a weighted directed graph with V vertices, find the shortest path between
 * every pair of vertices. Handle negative weights but not negative cycles.
 *
 * Approach: Dynamic programming. For each intermediate vertex k, update dist[i][j]
 * if going through k gives a shorter path: dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]).
 *
 * Time Complexity: O(V^3)
 * Space Complexity: O(V^2)
 */
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define INF 1e9

void floydWarshall(vector<vector<double>>& dist, int V) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

int main() {
    int V = 4;
    vector<vector<double>> dist = {
        {0,   3,   INF, 7  },
        {8,   0,   2,   INF},
        {5,   INF, 0,   1  },
        {2,   INF, INF, 0  }
    };
    floydWarshall(dist, V);
    cout << "All-pairs shortest paths:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF) cout << "INF ";
            else cout << dist[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}
