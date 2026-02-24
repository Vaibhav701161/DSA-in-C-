/*
 * DAY 61: Trie - Insert and Search
 *
 * Problem Statement:
 * Implement a Trie data structure with the following operations:
 * - insert(word): Inserts a word into the trie.
 * - search(word): Returns true if the word is in the trie.
 * - startsWith(prefix): Returns true if any word starts with prefix.
 *
 * Approach: Each node has 26 children (for lowercase letters) and an isEnd flag.
 *
 * Time Complexity: O(L) per operation where L is word length
 * Space Complexity: O(total characters)
 */
#include <iostream>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() : isEnd(false) {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple")   << endl; // 1
    cout << trie.search("app")     << endl; // 0
    cout << trie.startsWith("app") << endl; // 1
    trie.insert("app");
    cout << trie.search("app")     << endl; // 1
    return 0;
}
