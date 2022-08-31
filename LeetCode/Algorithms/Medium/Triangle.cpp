// Recursive Solution [TLE]
// 1. Move to lower-left element (i + 1 and j)
// 2. Move to lower-right element (i + 1 and j + 1)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {      
        int n = triangle.size(); 
        return dfs(0, 0, n, triangle); 
    }

    int dfs(int i, int j, int n, vector<vector<int> &triangle) {
        if(i == n) return 0; 
        int lower_left = triangle[i][j] + dfs(i+1, j, n, triangle); 
        int lower_right = triangle[i][j] + dfs(i+1, j+1, n, triangle); 
        return min(lower_left, lower_right); 
    }
};

// Time Complexity: O(2ⁿ)
// Space Complexity: O(n)

// Top-Down DP or Memoization [Accepted] 
// This is the essence of memoization.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); 
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(0, 0, n, triangle, memo);
    }

    int dfs(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &memo) {
        if(i == n) return 0; 

        if(memo[i][j] != -1) return memo[i][j];

        int lower_left = triangle[i][j] + dfs(i+1, j, n, triangle, memo); 
        int lower_right = triangle[i][j] + dfs(i+1, j+1, n, triangle, memo); 

        memo[i][j] =  min(lower_left, lower_right);

        return memo[i][j];
    }
};

// Time Complexity: O(n²)
// Space Complexity: O(n²)




