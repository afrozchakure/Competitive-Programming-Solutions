// Rotate matrix anticlockwise

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int rows = mat.size();  // 4
        int N = rows;
        int cols = mat[0].size();  // 4
        for(int x=0; x<N/2; x++)   
            for(int y=x; y<N-x-1; y++)
            {
                int temp = mat[x][y];  // 0, 0 -- 0, 1 -- 0, 2 -- 1, 0 -- 1, 1
                mat[x][y] = mat[y][N-1-x];  // 0, 3 -- 1, 3 -- 2, 3 -- 0, 2 -- 1, 2
                mat[y][N-1-x] = mat[N-1-x][N-1-y]; // 3, 3 -- 3, 2 -- 3, 1 -- 2, 3 -- 2, 2
                mat[N-1-x][N-1-y] = mat[N-1-y][x];  // 3, 0 -- 2, 0 -- 1, 0 -- 3, 1 -- 2, 1
                mat[N-1-y][x] = temp;
            }
    }
};

// Time Complexity - O(n**2)
// Space Complexity - O(1)