// Memoization 
// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        return dfs(cost, time, cost.size(), 0); 
    }

    int dfs(vector<int> &cost, vector<int> &time, int remain, int i) {
        if(remain <= 0) {
            return 0; 
        }

        if(i == cost.size()) {
            return INT_MAX;
        }

        int pain = dfs(cost, time, remain - 1 - time[i], i + 1); 
        int skip = dfs(cost, time, remain, i+1); 
        return min(pain, skip); 
    }
};
