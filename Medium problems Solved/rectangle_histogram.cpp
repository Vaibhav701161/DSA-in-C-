// largest_rectangle_histogram.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Monotonic stack approach.
  For each bar, find previous & next smaller bar.
  Time: O(n)
*/

int largestRectangleArea(vector<int>& h){
    int n=h.size();
    vector<int> left(n), right(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && h[st.top()]>=h[i]) st.pop();
        left[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && h[st.top()]>=h[i]) st.pop();
        right[i]=st.empty()?n:st.top();
        st.push(i);
    }
    int area=0;
    for(int i=0;i<n;i++)
        area=max(area,h[i]*(right[i]-left[i]-1));
    return area;
}

int main(){
    vector<int> h={2,1,5,6,2,3};
    cout<<"Largest Rectangle: "<<largestRectangleArea(h)<<'\n';
}
