/*
73. Set Matrix Zeroes
Medium
Topics
Companies
Hint
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
*/

// brute force approach

function mark row(i){
    for(int i=0;i<n;i++){
        if(arr[i][j] !=0){
            arr[i][j] = -1;
        }
    }
}
function markrow(j){
    for (int i=0;i<m;i++){
        if(arr[i][j]!=0){
            arr[i][j]=-1;
        }
    }
}

for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        if(arr[i][j]==0){
            markrow(i);
            markcol(j);
        }
    }
}

for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        if(arr[i][j]==-1){
            arr[i][j]=0;
        }
    }
}