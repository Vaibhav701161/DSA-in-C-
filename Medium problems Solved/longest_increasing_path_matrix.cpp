// 41_longest_increasing_path_matrix.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  DFS + memoization.
  For each cell, recursively compute the longest path starting there.
  Use dp[r][c] to cache results.
  Time: O(m*n)
*/

int m, n;
vector<vector<int>> dp;
vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

int dfs(const vector<vector<int>>& matrix, int r, int c) {
    if (dp[r][c] != -1) return dp[r][c];
    int best = 1;
    for (auto &d : dirs) {
        int nr = r + d[0], nc = c + d[1];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c]) {
            best = max(best, 1 + dfs(matrix, nr, nc));
        }
    }
    return dp[r][c] = best;
}

int longestIncreasingPath(const vector<vector<int>>& matrix) {
    m = matrix.size();
    if (m == 0) return 0;
    n = matrix[0].size();
    dp.assign(m, vector<int>(n, -1));
    int ans = 0;
    for (int i=0;i<m;++i) for (int j=0;j<n;++j)
        ans = max(ans, dfs(matrix, i, j));
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };
    cout << "Longest increasing path length: " << longestIncreasingPath(matrix) << '\n';
    return 0;
}
    if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
        if (curSize == capacity) {
            DLList* list = freqList[minFreq];
            Node* nodeToRemove = list->removeLastNode();
            keyNode.erase(nodeToRemove->key);
            delete nodeToRemove;
            curSize--;
        }
        Node* newNode = new Node(key, value);
        keyNode[key] = newNode;
        if (freqList.find(1) == freqList.end()) {
            freqList[1] = new DLList();
        }
        freqList[1]->addNode(newNode);
        minFreq = 1;
        curSize++;
    } else {
        node->value = value;
        updateFreq(node);
    }
}
    int n = 8;
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);
    cout << "Total solutions: " << solutions.size() << endl;
    printSolution(solutions);
    return 0;
}
    return node->value;
}
        updateFreq(node);
    }
}
    int n = 8;
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);
    cout << "Total solutions: " << solutions.size() << endl;
    printSolution(solutions);
    return 0;
}
    return node->value;
}
        updateFreq(node);
    }
}
    int n = 8;
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);
    cout << "Total solutions: " << solutions.size() << endl;
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
    return node->value;
}
        updateFreq(node);
    }
}                               int n = 8;
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);
    cout << "Total solutions: " << solutions.size() << endl;
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
    return node->value;
}
        updateFreq(node);
    }
}