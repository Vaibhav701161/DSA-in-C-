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

// time complexity is O(n*m) and space complexity is O(1)

// Better approach

// 1. Use first row and first column as markers
// 2. Traverse the matrix and mark the first row and first column
// 3. Traverse the first row and first column to mark the rest of the matrix
// 4. Traverse the matrix and set the elements to 0 if the first row or first column is marked
// 5. Set the first row and first column to 0 if they are marked
// 6. Return the matrix

col[m] = {0};
row[n] = {0};

for(int i=0;i<n;i+=){
    for(int j=0;j<m;j++){
        if(arr[i][j]==0){
            col[j]=1;
            row[i]=1;
        }
    }
}

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(col[j]==1 || row[i]==1){
            arr[i][j]=0;
        }
    }
}

// time complexity is O(n*m) and space complexity is O(1)

// Optimized approach

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            
            vector<int> row(n, 0);
            vector<int> col(m, 0);
    
            // Step 1: Mark rows and columns that need to be set to zero
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == 0) {
                        row[i] = 1;
                        col[j] = 1;
                    }
                }
            }
    
            // Step 2: Update the matrix based on marked rows and columns
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (row[i] == 1 || col[j] == 1) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    };
    