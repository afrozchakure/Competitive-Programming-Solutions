// - Here only effective solution works 
// - Time Complexity - O(N * K), where K = 2 
// - Space Complexity - O(N * K)
// - Refer solution here (need to watch this, have seen only solution for Best Time to Buy and Sell stoack IV, you can use the optimized solution from there): https://www.youtube.com/watch?v=q4Vr307dOzs
// - It uses only the space optimized solution from Best Time to Buy and Sell Stock III
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        int k = 2; 
        vector<vector<int>> dp(k+1, vector<int>(n, 0)); 
        
        for(int i=1; i<=k; i++) {
            int effectivePrice = prices[0];  // set to initial price in prices array
            for(int j=1; j<n; j++) {
                dp[i][j] = max(dp[i][j-1], prices[j] - effectivePrice); 
                effectivePrice = min(effectivePrice, prices[j] - dp[i-1][j]); 
            }
        }
        return dp[k][n-1]; 
    }
    
//     int helper(int k, int x, vector<vector<int>> &dp, vector<int> &prices) {
//         int maxProfit = 0;
        
//         for(int i=0; i<x; i++) {
//             maxProfit = max(maxProfit, prices[x] - prices[i] + dp[k-1][i]);
//         }
//         return maxProfit; 
//     }
};

