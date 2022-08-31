// - Refer Solution here: https://leetcode.com/problems/combination-sum-iv/discuss/1166177/Short-and-Easy-w-Explanation-or-Optimization-from-Brute-Force-to-DP-Solution
// Recursive solution
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0) {
            return 1; 
        }
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= target)
                ans += combinationSum4(nums, target - nums[i]);   
        } 
        return ans;
    }
};

// Time Compleiy - O(N * T) 
// Space Complexity - O(T), T is the number of recursive calls

// Top-Down Approach - DP
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1); 
        return helper(nums, helper, dp); 
    }

    int helper(vector<int>& nums, int target, vector<int>& dp) {
        if(target == 0) return 1; 
        if(dp[target] != -1) return dp[target]; 
        /// recursive code starts 
        dp[target] = 0; 
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= target) {
                dp[target] += helper(nums, target - nums[i], dp);
            }
        }

        return dp[target];
    }
};

// Time Complexity - O(N * T) 
// Space Complexity - O(T)


// Bottom-up solution - DP
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target + 1); 
        dp[0] = 1; 
        for(int currTarget=1; currTarget <= target; currTarget++) {
            for(auto &num: nums) {
                if(num <= currTarget) {
                    dp[currTarget] += dp[currTarget - num];   
                }
            }
        }
        return dp[target];
    }
};

// Time Complexity - O(N * T) 
// Space Complexity - O(T)