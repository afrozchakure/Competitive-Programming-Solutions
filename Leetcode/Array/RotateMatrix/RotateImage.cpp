// Rotating a Matrix clockwise

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        transpose(matrix, rows, cols);
        reverse(matrix, rows, cols);           
        // printMatrix(matrix, rows, cols);
        // printMatrix(matrix, rows, cols);
    }
    void transpose(vector<vector<int>>& matrix, int rows, int cols){
        for(int i=0; i<rows; i++)    
            for(int j=i; j<cols; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
    void reverse(vector<vector<int>>& matrix, int rows, int cols){
        for(int i=0; i<rows; i++)
            for(int j=0, k=cols-1; j<k; j++, k--)
                swap(matrix[i][j], matrix[i][k]);
    }
    void printMatrix(vector<vector<int>>& matrix, int rows ,int cols)
    {
        for(int i=0; i<rows; i++)  
        {
            for(int j=0; j<cols; j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }       
    }
    // 1. Transpose
    // 2. Reverse  
};

// Time Complexity - O(n**2) # Shape of matrix
// Space Complexity - O(1) 

// Method - 2 (Naive approach)
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int rows = mat.size();  // 4
        int N = rows;
        int cols = mat[0].size();  // 4
        for(int x=0; x<N/2; x++)   
            for(int y=x; y<N-x-1; y++)
            {
                int temp = mat[N-1-y][x];
                mat[N-1-y][x] = mat[N-1-x][N-1-y];  // 3, 0 -- 2, 0 -- 1, 0 -- 3, 1 -- 2, 1
                mat[N-1-x][N-1-y] = mat[y][N-1-x];  // 3, 3 -- 3, 2 -- 3, 1 -- 2, 3 -- 2, 2
                mat[y][N-1-x] = mat[x][y];   // 0, 3 -- 1, 3 -- 2, 3 -- 0, 2 -- 1, 2
                mat[x][y] = temp; // 0, 0 -- 0, 1 -- 0, 2 -- 1, 0 -- 1, 1
            }
            // To get anti-clockwise
            // just reverse the assignments and reverse their order
    }
};

// Time Complexity - O(n**2)
// Space Complexity - O(1)

// [
//   [ 5, 1, 9',11],
//   [ 2', 4, 8,10],
//   [13, 3, 6, 7'],
//   [15,14',12,16]
// ], 

// rotate the input matrix in-place such that it becomes:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]