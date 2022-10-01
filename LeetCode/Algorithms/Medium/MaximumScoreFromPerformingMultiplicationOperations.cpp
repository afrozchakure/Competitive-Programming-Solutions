class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, vector<int>& multipliers, int l, int r, int index) {
        // base condition 
        int n = nums.size(); 
        int m = multipliers.size(); 
        if(index >= m) return 0;    

        
        // memo 
        if(dp[index][l] != INT_MIN) {
            return dp[index][l];
        }

        int x = multipliers[index]; 
        // choices 
        return dp[index][l] = max(nums[l] * x + solve(nums, multipliers, l+1, r, index+1), nums[r] * x + solve(nums, multipliers, l, r-1, index+1));
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // n >= m 
        // nums and multipliers 

        int n = nums.size(); 
        int m = multipliers.size(); 
        int l = 0; 
        int r = n-1
        int index =0 ; 
        dp.assign(m + 1, vector<int>(m + 1, INT_MIN)); // initialized dp with -1 at every place
        return solve(nums, multipliers, l, r, index);         
        
    }
};

// If there are Choices and Optimization, think about Dynamic Programming 
