/*
Problem statement
You are given a sorted integer array 'arr' of size 'n'.



You need to remove the duplicates from the array such that each element appears only once.



Return the length of this new array.



Note:
Do not allocate extra space for another array. You need to do this by modifying the given input array in place with O(1) extra memory. 


For example:
'n' = 5, 'arr' = [1 2 2 2 3].
The new array will be [1 2 3].
So our answer is 3.
*/

// Brute force approach
// Time complexity: O(nlogn)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

set <int> getUniqueElements(vector <int> &arr){
    set <int> s ;
    for(int i=0;i<arr.size;i++){
        s.insert(arr[i]);
    }
}

int index = 0;
int removeDuplicates(vector<int>& arr){
    set <int> s = getUniqueElements(arr);
    for(auto i : s){
        arr[index++] = i;
    }
    return s.size();
}

int main(){
    vector <int> arr = {1,2,2,2,3};
    cout<<removeDuplicates(arr);
    return 0;
}

// Optimized approach
// Time complexity: O(n)
// Space complexity: O(1)

int removeDuplicates(vector<int> &arr, int n) {
	int i =0 ;
	for (int j =1 ; j < n; j++){
		if(arr[j]!= arr[i]){
			arr[i+1] = arr[j];
					i++;

		}
	}
	return i+1 ;
}