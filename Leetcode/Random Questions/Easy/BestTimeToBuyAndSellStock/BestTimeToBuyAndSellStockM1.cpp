class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxPro = 0;
        int min_val = INT_MAX;
        for(int i=0; i<nums.size(); ++i)
        {
            min_val = min(min_val, nums[i]);
            maxPro = max(maxPro, nums[i]-min_val);
        }
        return maxPro;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
