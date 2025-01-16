#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<string>> &solutions) {
    for (auto &sol : solutions) {
        for (auto &row : sol) {
            cout << row << "\n";
        }
        cout << "------------------\n";
    }
}

bool isSafe(vector<string> &board, int row, int col, int n) {
    for (int i = 0; i < row; i++) 
        if (board[i][col] == 'Q') return false;
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j] == 'Q') return false;
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) 
        if (board[i][j] == 'Q') return false;
    return true;
}

void solve(vector<string> &board, int row, int n, vector<vector<string>> &res) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(board, row + 1, n, res);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n = 8;
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);
    cout << "Total solutions: " << solutions.size() << endl;
    printSolution(solutions);
    return 0;
}
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreq(node);
        } else {
            if(curSize == capacity) {
                DLList* list = freqList[minFreq];
                Node* nodeToRemove = list->removeLastNode();
                keyNode.erase(nodeToRemove->key);
                delete nodeToRemove;
                curSize--;
            }
            Node* newNode = new Node(key, value);
            minFreq = 1;
            DLList* list = freqList[minFreq];
            if(!list) {
                list = new DLList();
                freqList[minFreq] = list;
            }
            list->addNode(newNode);
            keyNode[key] = newNode;
            curSize++;
        }
    }
            cout << lfu.get(2) << endl; // Output: 20
    return 0;
}
// n_queen_solver.cpp
#include <bits/stdc++.h>
using namespace std;
/*
  Backtracking solution to the N-Queens problem.
  Place queens row by row and check for safety.
*/
void printSolution(vector<vector<string>> &solutions) {
    for (auto &sol : solutions) {
        for (auto &row : sol) {
            cout << row << "\n";
        }
        cout << "------------------\n";
    }
}
bool isSafe(vector<string> &board, int row, int col, int n) {
    for (int i = 0; i < row; i++) 
        if (board[i][col] == 'Q') return false;
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j] == 'Q') return false;
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) 
        if (board[i][j] == 'Q') return false;
    return true;
}
void solve(vector<string> &board, int row, int n, vector<vector<string>> &res) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(board, row + 1, n, res);
            board[row][col] = '.';
        }
    }
}
int main() {
    int n = 8;
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, solutions);
    cout << "Total solutions: " << solutions.size() << endl;
    printSolution(solutions);
    return 0;
}
/*
  Backtracking solution to the N-Queens problem.
  Place queens row by row and check for safety.
*/
#include <bits/stdc++.h>
using namespace std;
void printSolution(vector<vector<string>> &solutions) {
    for (auto &sol : solutions) {
        for (auto &row : sol) {
            cout << row << "\n";
        }
        cout << "------------------\n";
    }
}