class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); 
        if(n < 2) {
            return 0;
        }
        vector<vector<int>> dp(k+1, vector<int>(n, 0));  // Space: O(KN)
        
        // Time - O(K*N*N)
        for(int i=1; i<=k; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = max(dp[i][j-1], helper(i, j, dp, prices)); 
            }
        }
        
        return dp[k][n-1]; 
    }

    // Profit by selling on current price (j) 
    // Profit = SP - BP 
    // For space optimized solution 
    // SP => price[j] 
    // BP => Effective Buy Price -> price[j] - previous profit (dp[k-1][j])
    
    // Time - O(N)
    int helper(int k, int x, vector<vector<int>> &dp, vector<int> &prices) {
        int maxProfit = 0; 
        
        for(int i=0; i<x; i++) {
            // Sell on day_x, buy on day_i and add profit from (i-1) transactions dp[k-1][i]
            maxProfit = max(maxProfit, prices[x] - prices[i] + dp[k-1][i]); 
        }
        return maxProfit; 
    }
};

// Time Complexity - O(K * N * N)
// Space Complexity - O(N * K) 

// Method - 2 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); 
        if(n < 2) {
            return 0;
        }
        vector<vector<int>> dp(k+1, vector<int>(n, 0));  // Space: O(KN)
        
        // Time - O(K*N*N)
        for(int i=1; i<=k; i++) {
            int effectiveBuyPrice = prices[0]; 
            for(int j=1; j<n; j++) {
                dp[i][j] = max(dp[i][j-1], prices[j] - effectiveBuyPrice); 
                effectiveBuyPrice = min(effectiveBuyPrice, prices[j] - dp[i-1][j]);
            } 
        }
        
        return dp[k][n-1]; 
    }

    // Profit by selling on current price (j) 
    // Profit = SP - BP 
    // For space optimized solution 
    // SP => price[j] 
    // BP => Effective Buy Price -> price[j] - previous profit (dp[k-1][j])
    
    // Time - O(N)
    int helper(int k, int x, vector<vector<int>> &dp, vector<int> &prices) {
        int maxProfit = 0; 
        
        for(int i=0; i<x; i++) {
            // Sell on day_x, buy on day_i and add profit from (i-1) transactions dp[k-1][i]
            maxProfit = max(maxProfit, prices[x] - prices[i] + dp[k-1][i]); 
        }
        return maxProfit; 
    }
};