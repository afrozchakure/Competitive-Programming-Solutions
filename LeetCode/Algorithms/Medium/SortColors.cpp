#include<unordered_set>
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int index = 0;
        while(index <= end && start < end)
        {
            if(nums[index] == 0)
            {
                nums[index] =  nums[start];
                nums[start] = 0;
                index++;
                start++;
            }
            else if(nums[index] == 2)
            {
                nums[index] = nums[end];
                nums[end] = 2;
                end--;
            }
            else{
                index++;
            }
        }
        
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
