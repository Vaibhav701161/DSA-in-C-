// word_break.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Word Break using DP.
  dp[i] = true if s[0..i-1] can be segmented.
  Time: O(n^2).
*/

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n+1,false);
    dp[0]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(dp[j] && dict.count(s.substr(j,i-j))){
                dp[i]=true; break;
            }
        }
    }
    return dp[n];
}

int main(){
    string s="leetcode";
    vector<string> dict={"leet","code"};
    cout<<"Word Break possible: "<<wordBreak(s,dict)<<'\n';
}
