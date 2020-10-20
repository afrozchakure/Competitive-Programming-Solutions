// Floyd's Tortoise And Hare (Cycle Detection) Algorithm

// Remember this

class Solution {
    public:
    int findDuplicates(vector<int>& nums){
        int slow_pointer = nums[0];
        int fast_pointer = nums[0];
        
        slow_pointer = nums[slow_pointer];
        fast_pointer = nums[fast_pointer];
        
        while(slow_pointer != fast_pointer)
        {
            slow_pointer = nums[slow_pointer];
            fast_pointer = nums[nums[fast_pointer]];
      
        }
        int a_pointer = nums[0];
        int b_pointer = slow_ponter;
        
        while(a_pointer != b_pointer)
        {
            a_pointer = nums[a_pointer];
            b_pointer = nums[b_pointer];
        }
        return a_pointer;
    }
}

// Time Complexity - O(n)
// Space Complexity - O(1)
