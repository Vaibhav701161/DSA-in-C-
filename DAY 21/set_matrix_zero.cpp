/*
73. Set Matrix Zeroes
Solved
Medium
Topics
premium lock icon
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
// brute force solution

for (int i = 0 ; i <n ; i++){
    for (int j = 0 ; j < m ; j++){

        if(arr[i][j] == 0){
            markRow[i];
            markCol[j];
        }
    }
}

void markRow(int i){
    for (int j = 0 ;j <m ; j++){
        if(arr[i][j] != 0){
            arr[i][j] = -1; // mark as zero
        }
    }
}

void markCol(int j){
    for (int i = 0 ;i <n ; i++){
        if(arr[i][j] != 0){
            arr[i][j] = -1; // mark as zero
        }
    }
}

for (int i = 0 ; i <n ; i++){
    for (int j = 0 ; j < m ; j++){
        if(arr[i][j] == -1){
            arr[i][j] = 0; // set to zero
        }
    }
}

// Better solution using first row and first column as markers

col[m] = {0}; // to mark columns
row[n] = {0}; // to mark rows

for (int i = 0 ; i < n ; i++){
    for ( int j = 0 ; j< m ; j++){
        if (matrix[i][j] == 0){
            row[i] = 1 ;
            col[j] = 1; // mark the row and column
        }
    }
}