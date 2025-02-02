// min_window_substring.cpp
#include <bits/stdc++.h>
using namespace std;

string minWindow(string s,string t){
    vector<int> need(128,0);
    for(char c:t) need[c]++;
    int required=t.size(),left=0,minLen=INT_MAX,start=0;
    for(int r=0;r<s.size();r++){
        if(need[s[r]]>0) required--;
        need[s[r]]--;
        while(required==0){
            if(r-left+1<minLen){ minLen=r-left+1; start=left; }
            need[s[left]]++;
            if(need[s[left]]>0) required++;
            left++;
        }
    }
    return minLen==INT_MAX?"":s.substr(start,minLen);
}

int main(){
    string s="ADOBECODEBANC",t="ABC";
    cout<<"Min window: "<<minWindow(s,t)<<'\n';
}
