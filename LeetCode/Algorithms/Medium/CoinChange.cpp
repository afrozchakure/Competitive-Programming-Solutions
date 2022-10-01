class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount+1);
        
        dp[0] = 0;
        
        for(int i=1; i<amount+1; i++)
        {
            for(auto &c: coins)
            {
                if(i - c >= 0)        
                {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }        
        return dp[amount] != (amount + 1) ? dp[amount] : -1;
    }
};

// Time Complexity - O(Amount * len(coin))
// Space Complexity - O(amount)


// Top Down - Memoization (Recursive solution) 

// Bottom up approach - True DP solution (solving in reverse order) 
// [1,3,4,5]
// minimum number of coins for summing to 0 is 0 
// minimum number of coins for summing to 1 is 1 
// minimum number of coins for summing to 2 is dp[2] = 1 + dp[1] 

// dp[i] = dp[i - coins[j]] + 1

// dp[7] = dp[1] + dp[7 - 1] = 1 + 2 = 3 
// 1 + dp[4] = 1 + 1 


// if a - c >= 0 // 

// dp[amount]