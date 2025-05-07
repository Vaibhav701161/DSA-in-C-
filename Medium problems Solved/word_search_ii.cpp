// word_search_ii.cpp
#include <bits/stdc++.h>
using namespace std;

struct Trie {
    bool end = false;
    array<Trie*, 26> next{};
    Trie() { next.fill(nullptr); }
};

void insertTrie(Trie* root, const string& s) {
    Trie* cur = root;
    for (char c : s) {
        int idx = c - 'a';
        if (!cur->next[idx]) cur->next[idx] = new Trie();
        cur = cur->next[idx];
    }
    cur->end = true;
}

void dfs(vector<vector<char>>& board, int r, int c, Trie* node, string& path, unordered_set<string>& found) {
    int m = board.size(), n = board[0].size();
    if (r < 0 || c < 0 || r >= m || c >= n) return;
    char ch = board[r][c];
    if (ch == '#') return;
    Trie* nxt = node->next[ch - 'a'];
    if (!nxt) return;
    path.push_back(ch);
    if (nxt->end) found.insert(path);
    board[r][c] = '#';
    dfs(board, r+1, c, nxt, path, found);
    dfs(board, r-1, c, nxt, path, found);
    dfs(board, r, c+1, nxt, path, found);
    dfs(board, r, c-1, nxt, path, found);
    board[r][c] = ch;
    path.pop_back();
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie* root = new Trie();
    for (auto &w : words) insertTrie(root, w);
    unordered_set<string> found;
    int m = board.size(), n = board[0].size();
    string path;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            dfs(board, i, j, root, path, found);
    vector<string> res(found.begin(), found.end());
    // cleanup omitted for brevity
    return res;
}

int main() {
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain","hike"};
    auto ans = findWords(board, words);
    cout << "Found words:\n";
    for (auto &w : ans) cout << w << '\n';
    return 0;
}
