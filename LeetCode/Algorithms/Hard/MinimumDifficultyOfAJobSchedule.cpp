class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size()) return -1; 

        vector<vector<int>> dp(d + 1, vector<int> (jobDifficulty.size(), -1)); 
        return solved(d, 0, jobDifficulty, dp); 
    }
    
    // DFS recursive function
    int solve(int d, int idx, vector<int>& jobDifficulty, vector<vector<int>> &dp) {
        if(d == 1) {
            int mx = 0; 
            while(idx < jobDifficulty.size()) {
                mx = max(mx, jobDifficulty[idx++]); 
            }
            return mx; 
        }

        // if substrcture is already solved, we directly return it 
        // memoization
        if(dp[d][idx] != -1) return dp[d][idx]; 

        int res = INT_MAX; 
        int mx = 0; 
        for(int i=idx; i<jobDifficulty.size()-d + 1; i++) {
            mx = max(mx, jobDifficulty[i]); 
            res = min(res, mx + solve(d-1, i+1, jobDifficulty, dp));
        }
        dp[d][idx] = res; 
        return dp[d][idx]; 
    }

};
// Time Complexity - O(d * jobDifficulty.size()) => O(N**2)
// Space Complexity - O(N**2)