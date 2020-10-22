class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int current_max = nums[0];
        int max_so_far = nums[0];
        
        for(int i=1; i<n; i++)
        {
            current_max = max(nums[i], current_max + nums[i]);
            max_so_far = max(current_max, max_so_far);
        }
        return max_so_far;
        
// Time Complexity - O(n)
// Space Complexity - O(1)
