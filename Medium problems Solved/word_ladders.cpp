#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;

        queue<pair<string,int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) return steps;

            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (dict.find(temp) != dict.end()) {
                        dict.erase(temp);
                        q.push({temp, steps+1});
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << "Shortest Ladder Length: " << sol.ladderLength("hit", "cog", wordList);
    return 0;
}
