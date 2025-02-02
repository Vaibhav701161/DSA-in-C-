// longest_pal_substring.cpp
#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s){
    int n=s.size(),start=0,len=1;
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    for(int i=0;i<n;i++) dp[i][i]=true;
    for(int i=0;i<n-1;i++)
        if(s[i]==s[i+1]){ dp[i][i+1]=true; start=i; len=2; }
    for(int l=3;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int j=i+l-1;
            if(s[i]==s[j] && dp[i+1][j-1]){
                dp[i][j]=true;
                if(l>len){ start=i; len=l; }
            }
        }
    }
    return s.substr(start,len);
}

int main(){
    string s="babad";
    cout<<"Longest Palindrome: "<<longestPalindrome(s)<<'\n';
}
