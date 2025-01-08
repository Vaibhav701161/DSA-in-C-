/*
Trie (Prefix Tree) + Word Search

Problem: Implement Trie, then given board of letters, check if a word exists.
*/

// trie_wordsearch.cpp
#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    bool end;
    unordered_map<char,TrieNode*> children;
    TrieNode():end(false){}
};

class Trie{
    TrieNode* root;
public:
    Trie(){root=new TrieNode();}
    void insert(string w){
        TrieNode* cur=root;
        for(char c:w){
            if(!cur->children[c]) cur->children[c]=new TrieNode();
            cur=cur->children[c];
        }
        cur->end=true;
    }
    bool search(string w){
        TrieNode* cur=root;
        for(char c:w){
            if(!cur->children[c]) return false;
            cur=cur->children[c];
        }
        return cur->end;
    }
};

bool dfs(vector<vector<char>>& board,int i,int j,string&word,int k){
    if(k==(int)word.size()) return true;
    if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[k]) return false;
    char tmp=board[i][j];
    board[i][j]='#';
    bool found=dfs(board,i+1,j,word,k+1)||dfs(board,i-1,j,word,k+1)||
               dfs(board,i,j+1,word,k+1)||dfs(board,i,j-1,word,k+1);
    board[i][j]=tmp;
    return found;
}

bool exist(vector<vector<char>>& board,string word){
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[0].size();j++)
            if(dfs(board,i,j,word,0)) return true;
    return false;
}

int main(){
    Trie t; t.insert("word");
    vector<vector<char>> board={{'w','o'},{'r','d'}};
    cout<<"Word exists: "<<exist(board,"word")<<'\n';
}
