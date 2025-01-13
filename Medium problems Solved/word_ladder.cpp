// 35_word_ladder.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Transform words by one-letter changes.
  Build intermediate patterns (wildcards) to connect words efficiently.
  Time: O(L * N) where L = word length, N = number words.
*/

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord)) return 0;

    int L = beginWord.size();
    unordered_map<string, vector<string>> combo;

    // Preprocess
    for (const string& word: wordSet) {
        for (int i = 0; i < L; ++i) {
            string key = word.substr(0,i) + '*' + word.substr(i+1);
            combo[key].push_back(word);
        }
    }

    queue<pair<string,int>> q;
    q.push({beginWord, 1});
    unordered_set<string> visited;
    visited.insert(beginWord);

    while (!q.empty()) {
        auto [word, depth] = q.front(); q.pop();
        for (int i = 0; i < L; ++i) {
            string key = word.substr(0,i) + '*' + word.substr(i+1);
            for (const string& next : combo[key]) {
                if (next == endWord) return depth + 1;
                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, depth+1});
                }
            }
            // optional: clear to prevent re-processing
            combo[key].clear();
        }
    }
    return 0;
}

int main() {
    string begin = "hit", endw = "cog";
    vector<string> words = {"hot","dot","dog","lot","log","cog"};
    cout << "Ladder length: " << ladderLength(begin, endw, words) << '\n';

    vector<string> words2 = {"hot","dot","dog","lot","log"};
    cout << "Ladder length (no cog): " << ladderLength(begin, endw, words2) << '\n';
    return 0;
}
