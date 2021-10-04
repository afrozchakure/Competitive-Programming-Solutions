class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length; 
        
         k = k % n;
        
        reverse(nums, 0, n-1); 
        reverse(nums, 0, k-1); 
        reverse(nums, k, n-1);
    }
    
    public void reverse(int[] nums, int start, int end) 
    {
        while(start < end)
        {
            int temp = nums[start]; 
            nums[start] = nums[end]; 
            nums[end] = temp; 
            start++;
            end--; 
        }
    }
}

// Time Complexity - O(N)
// Space Complexity - O(1), no additional space required