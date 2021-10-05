class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        int index = -1;
        
        for(int i=1; i<n; i++)
        {
            if(nums[i-1] >= nums[i])
            {
                count++;
                index = i;
            }
        }
        cout<<count<<"\n";
        if(count > 1)
            return false;
        
        // if count = 0
        if(count == 0)
            return true;
        
        // if last index is removed 
        if(index == n-1 || index == 1)
            return true;
        
        // if a[index] is removed, check the next ones 
        if(nums[index-1] < nums[index+1])
            return true;
        
        // if a[index-1] is removed, 
        if(nums[index-2] < nums[index])
            return true;
        
        
        
        return false;
    }
};

// Time complexity - O(N)
// Space Complexity - O(1)
