class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftbox(n, 0);
        vector<int> rightbox(n, 0);
        int leftMax = 0;
        int rightMax = 0;
        
        for(int i=0; i<n; i++)
        {
            rightMax = max(rightMax, nums[n-i-1]);
            rightbox[n-i-1] = rightMax;

            leftMax = max(leftMax, nums[i]);
            leftbox[i] = leftMax;
            
            // cout<<leftbox[i]<<" ";
        }
        
        int result = 0;
        
        for(int i=0; i<n; i++)
        {
            result += min(rightbox[i], leftbox[i]) - nums[i];
        }
        
        return result;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N), since we're using a vector
