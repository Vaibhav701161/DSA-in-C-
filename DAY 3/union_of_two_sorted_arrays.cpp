/*
Union of 2 Sorted with Duplicates
Difficulty: MediumAccuracy: 31.39%Submissions: 432K+Points: 4Average Time: 20m
Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
Output: 1 2 3 4 5
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
Output: 1 2
Explanation: Distinct elements including both the arrays are: 1 2.
Constraints:
1  <=  a.size(), b.size()  <=  105
-109  <=  a[i] , b[i]  <=  109
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


set <int> st;

for(int i=0;i<a.size();i++)
{
    st.insert(a[i]);
}
for(int i=0;i<b.size();i++)
{
    st.insert(b[i]);
}
union{st.size()};

for(auto i:st)
{
    union[i++] = it ; 
    union.add(it);
}
