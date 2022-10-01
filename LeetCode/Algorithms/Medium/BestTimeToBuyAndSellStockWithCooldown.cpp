class Solution {
public:
    map<pair<int, bool>, int> dp; 
    int maxProfit(vector<int>& prices) {
        // State: Buying or Selling 
        // If Buy -> i + 1 
        // If Sell -> i + 2 

        // Key = (i, buying) val = max_profit
        // map<pair<int, bool>, int> dp; 
        return dfs(0, true, prices); 
    }

    int dfs(int i, bool buying, vector<int> &prices) {
        if(i >= prices.size()) {
            return 0; 
        }

        if(dp.find(make_pair(i, buying)) != dp.end()) {
            return dp[make_pair(i, buying)]; 
        }
        
        int cooldown = 0; 
        if(buying) {
            int buy = dfs(i + 1, !buying, prices) - prices[i]; 
            cooldown = dfs(i + 1, buying, prices); 
            dp[make_pair(i, buying)] = max(buy, cooldown); 
        } else {
            int sell = dfs(i + 2, !buying, prices) + prices[i]; 
            cooldown = dfs(i + 1, buying, prices); 
            dp[make_pair(i, buying)] = max(sell, cooldown); 
        }
        return dp[make_pair(i, buying)]; 
    }
};