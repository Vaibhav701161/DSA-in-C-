/*
Generate Parentheses (backtracking)

Problem: Given n, generate all valid parentheses sequences of length 2n.
*/

#include <bits/stdc++.h>
using namespace std;

void backtrack(string& curr, int open, int close, int n, vector<string>& result) {
    if (curr.length() == 2 * n) {
        result.push_back(curr);
        return;
    }
    if (open < n) {
        curr.push_back('(');
        backtrack(curr, open + 1, close, n, result);
        curr.pop_back();
    }
    if (close < open) {
        curr.push_back(')');
        backtrack(curr, open, close + 1, n, result);
        curr.pop_back();
    }
}

vector<string> generateParentheses(int n) {
    vector<string> result;
    string curr;
    backtrack(curr, 0, 0, n, result);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 3;
    auto res = generateParentheses(n);
    for (const string& s : res) {
        cout << s << '\n';
    }
    return 0;
}
