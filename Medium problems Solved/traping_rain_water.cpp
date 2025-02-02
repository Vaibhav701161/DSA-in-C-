// trapping_rain_water.cpp
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& h){
    int l=0,r=h.size()-1,leftMax=0,rightMax=0,water=0;
    while(l<r){
        if(h[l]<h[r]){
            if(h[l]>=leftMax) leftMax=h[l];
            else water+=leftMax-h[l];
            l++;
        }else{
            if(h[r]>=rightMax) rightMax=h[r];
            else water+=rightMax-h[r];
            r--;
        }
    }
    return water;
}

int main(){
    vector<int> h={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"Trapped Water: "<<trap(h)<<'\n';
}
