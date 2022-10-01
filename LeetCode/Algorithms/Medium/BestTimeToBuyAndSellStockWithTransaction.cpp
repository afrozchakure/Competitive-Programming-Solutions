class Solution {
public:
    map<pair<int, bool>, int> dp; 
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(); 
        return dfs(0, true, prices, fee); 
    }
    
    int dfs(int i, bool buying, vector<int> &prices, int fee) {
        if(i >= prices.size()) return 0; 
        
        if(dp.find(make_pair(i, buying)) != dp.end()) {
            return dp[make_pair(i, buying)]; 
        }
        
        int cooldown = 0; 
        
        if(buying) {
            int buy = dfs(i+1, !buying, prices, fee) - prices[i]; 
            cooldown = dfs(i+1, buying, prices, fee); 
            dp[make_pair(i, buying)] = max(buy, cooldown); 
        } else {
            int sell = dfs(i+1, !buying, prices, fee) + prices[i] - fee; 
            cooldown = dfs(i + 1, buying, prices, fee); 
            dp[make_pair(i, buying)] = max(sell, cooldown); 
        }
        return dp[make_pair(i, buying)]; 
    }
};

// - Dp Solution (Not space optimized) 
// - Time Complexity - O(N) 
// - Space Complexity - O(N), since we're using a map
// - It is an extension of Buy and Sell stock with Cool down problem : 
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/ ... just deducting the f

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       int aheadNotBuy, aheadBuy, currBuy, currNotBuy; 
       int n = prices.size(); 
       aheadBuy = aheadNotBuy = 0; 

       for(int i=n-1; i >= 0; i--) {
        // sell 
        currNotBuy = max(prices[i] + aheadBuy - fee, 0 + aheadNotBuy); 

        // buy 
        currBuy = max(aheadNotBuy - prices[i], 0 + aheadBuy); 

        aheadBuy = currBuy; 
        aheadNotBuy = currNotBuy; 
       }

       return aheadBuy; 
    }
};