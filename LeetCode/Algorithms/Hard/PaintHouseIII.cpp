#define ll long long 
class Solution {
public:
    ll dp[105][25][105];
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // memset dp with -1
        memset(dp, -1, sizeof(dp)); 

        // calculate answer using recursive dp 
        ll ans = solve(houses, 0, cost, n+1, m, n, target); 
        if(ans == INT_MAX) {
            return -1;  // if answer comes out to be INT_MAX then combination is not possible 
        }

        return ans; 
    }

    ll solve(vector<int>& houses, ll index, vector<vector<int>>& cost, ll prev, ll m, ll n, ll target) {
        if(target < 0) {
            return INT_MAX; 
        }

        if(index == m) {  // if we have visited all hosues 
            if(target == 0) { // if neighbours are same as required, then no more cost is required
                return 0; 
            }
            return INT_MAX;  // if neighbours are not same, then this build is not valid 
        }

        if(dp[index][prev][target] != -1) 
            return dp[index][prev][target]; 

        if(houses[index] != 0) {  // if house is already coloured
            return dp[index][prev][target] = solve(houses, index+1, cost, houses[index], m, n, target - (prev != houses[index])); 
        }

        ll ans = INT_MAX;   // If we are coloring house, then find minimum cost 
        for(int i=1; i<=n; i++) {
            ans = min(ans, cost[index][i-1] + solve(houses, index+1, cost, i, m, n, target - (prev != i)));
        }
        return dp[index][prev][target] = ans; 
    }
};