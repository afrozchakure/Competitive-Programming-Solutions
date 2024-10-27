class Solution {
public:
    int dp[205][205];
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp)); 
        int n = grid.size(); 
        int ans = INT_MAX; 
        for(int i=0; i<n; i++) {
            ans = min(ans, ok(grid, 0, i)); 
        }

        return ans; 
    }

    int ok(vector<vector<int>> &grid, int row, int column) {
        int n = grid.size(); 
        if(row == grid.size() - 1) {
            return grid[row][column]; 
        }

        if(row == grid.size()) {
            return 0; 
        }

        if(dp[row][column] != -1) {
            return dp[row][column];
        }

        int ans = INT_MAX; 
        for(int i=0; i<n; i++) {
            if(i != column) {
                ans = min(ans, ok(grid, row + 1, i)); 
            }
        }
        
        dp[row][column] = ans + grid[row][column]; 
        return dp[row][column]; 
    }
};