// spiral_matrix.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Spiral traversal: boundaries shrinking.
*/

vector<int> spiralOrder(vector<vector<int>>& mtx){
    int top=0,bottom=mtx.size()-1;
    int left=0,right=mtx[0].size()-1;
    vector<int> res;
    while(top<=bottom && left<=right){
        for(int j=left;j<=right;j++) res.push_back(mtx[top][j]); top++;
        for(int i=top;i<=bottom;i++) res.push_back(mtx[i][right]); right--;
        if(top<=bottom){
            for(int j=right;j>=left;j--) res.push_back(mtx[bottom][j]); bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--) res.push_back(mtx[i][left]); left++;
        }
    }
    return res;
}

int main(){
    vector<vector<int>> m={{1,2,3},{4,5,6},{7,8,9}};
    auto res=spiralOrder(m);
    cout<<"Spiral order: ";
    for(int x:res) cout<<x<<' ';
    cout<<'\n';
}
