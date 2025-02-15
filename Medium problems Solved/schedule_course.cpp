#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0) q.push(i);

        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            for (int next : adj[course]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }

        return count == numCourses;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> prereq = {{1, 0}};
    int n = 2;
    cout << (sol.canFinish(n, prereq) ? "Yes, can finish courses" : "No, cannot finish courses") << endl;
    return 0;
}
