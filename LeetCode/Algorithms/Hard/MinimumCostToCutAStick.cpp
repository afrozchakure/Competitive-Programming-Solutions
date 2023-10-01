class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        map<pair<int, int>, int> m; 

        return dfs(0, n); 
    }

    dfs(int left, int right) {
        if(right - left == 1) {
            return 0; 
        }    
        if(dp[make_pair(left, right)]) {
            return dp[make_pair(left, right)];
        }

        float res = INT_MAX; 

        for(auto &c: cuts) {
            if(left < c < right) {
                res = min(res, (r - l) + dfs(l, c) + dfs(c, r)); 
            }
        }

        if(res == INT_MAX) {
            res = 0; 
        } 

        dp[make_pair(left, right)] = res; 
        return res; 
    }
};