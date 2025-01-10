// coin_change.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  DP: coin change.
  dp[i] = min coins to make i.
  Time: O(amount * coins).
*/

int coinChange(vector<int>& coins,int amt){
    vector<int> dp(amt+1,1e9);
    dp[0]=0;
    for(int i=1;i<=amt;i++){
        for(int c:coins){
            if(i-c>=0) dp[i]=min(dp[i],dp[i-c]+1);
        }
    }
    return dp[amt]==1e9?-1:dp[amt];
}

int main(){
    vector<int> coins={1,2,5};
    int amt=11;
    cout<<"Min coins: "<<coinChange(coins,amt)<<'\n';
}
