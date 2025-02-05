/*
Course Schedule II (topological sort — return order)

Problem: Given numCourses and prerequisites pairs [a,b] meaning b -> a, find a valid order (topological ordering) or return empty if cycle. Use Kahn's algorithm
*/

// course_schedule_ii.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Course Schedule II: find topological order using Kahn's algorithm (BFS).
  Return vector<int> order (size numCourses) or empty if impossible.
*/

vector<int> findOrder(int numCourses, vector<pair<int,int>>& prerequisites) {
    vector<vector<int>> g(numCourses);
    vector<int> indeg(numCourses, 0);
    for (auto &p : prerequisites) {
        int a = p.first, b = p.second; // b -> a
        g[b].push_back(a);
        ++indeg[a];
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) if (indeg[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    if ((int)order.size() != numCourses) return {}; // cycle detected
    return order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 4;
    vector<pair<int,int>> prereq = {{1,0},{2,0},{3,1},{3,2}};
    auto ord = findOrder(n, prereq);
    if (ord.empty()) cout << "No valid order (cycle)\n";
    else {
        cout << "Course order:\n";
        for (int x : ord) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
