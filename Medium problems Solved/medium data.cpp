// median_stream.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Median finder using two heaps:
  - max-heap left (lower half)
  - min-heap right (upper half)
*/

class MedianFinder{
    priority_queue<int> left; // max-heap
    priority_queue<int,vector<int>,greater<int>> right; // min-heap
public:
    void addNum(int num){
        left.push(num);
        right.push(left.top());
        left.pop();
        if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }
    }
    double findMedian(){
        if(left.size()>right.size()) return left.top();
        return (left.top()+right.top())/2.0;
    }
};

int main(){
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout<<mf.findMedian()<<'\n'; //1.5
    mf.addNum(3);
    cout<<mf.findMedian()<<'\n'; //2
}
