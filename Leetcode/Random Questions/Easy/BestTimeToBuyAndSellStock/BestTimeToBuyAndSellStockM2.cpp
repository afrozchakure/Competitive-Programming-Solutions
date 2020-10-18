class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int max_profit = 0;
        int min_value = INT_MAX;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < min_value)
                min_value = nums[i];
            if(max_profit < nums[i] - min_value)
                max_profit = nums[i] - min_value;
        }
        return max_profit;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
