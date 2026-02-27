/*
 * DAY 64: N-Queens Problem (Backtracking)
 *
 * Problem Statement:
 * Place n queens on an n x n chessboard such that no two queens attack each other.
 * Return all distinct solutions. Each solution is a board configuration.
 *
 * Approach: Backtracking. Place queens row by row.
 * For each row, try all columns. Check if placement is safe (no conflicts in
 * column, main diagonal, anti-diagonal). If safe, place and recurse.
 *
 * Time Complexity: O(n!)
 * Space Complexity: O(n^2)
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) if (board[i][col] == 'Q') return false;
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}

void solve(int row, int n, vector<string>& board, vector<vector<string>>& results) {
    if (row == n) { results.push_back(board); return; }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(row + 1, n, board, results);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> results;
    vector<string> board(n, string(n, '.'));
    solve(0, n, board, results);
    return results;
}

int main() {
    int n = 4;
    auto solutions = solveNQueens(n);
    cout << "Number of solutions for " << n << "-Queens: " << solutions.size() << endl;
    for (auto& sol : solutions) {
        for (auto& row : sol) cout << row << endl;
        cout << "---" << endl;
    }
    return 0;
}
