// 47_n_queens.cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solutions;
vector<string> board;
int N;

bool isSafe(int row, int col) {
    for (int i=0;i<row;++i) {
        if (board[i][col]=='Q') return false;
        int d = row-i;
        if (col-d>=0 && board[i][col-d]=='Q') return false;
        if (col+d<N && board[i][col+d]=='Q') return false;
    }
    return true;
}

void solveNQ(int row) {
    if (row==N) { solutions.push_back(board); return; }
    for (int col=0; col<N; ++col) {
        if (isSafe(row,col)) {
            board[row][col]='Q';
            solveNQ(row+1);
            board[row][col]='.';
        }
    }
}

int main() {
    N=4;
    board.assign(N, string(N,'.'));
    solveNQ(0);
    cout << "Solutions:\n";
    for (auto &sol: solutions) {
        for (auto &row: sol) cout << row << '\n';
        cout << "----\n";
    }
    return 0;
}
void printSolution(const vector<vector<string>>& solutions) {
    for (const auto& sol : solutions) {
        for (const auto& row : sol) {
            cout << row << '\n';
        }
        cout << "----\n";
    }
}