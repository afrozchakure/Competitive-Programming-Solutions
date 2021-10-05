class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high)
        {
             int mid = ((low + high) / 2);
            if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else if(nums[mid] == target)
            {
                return mid;
            }
        }
        return -1;
    }
};

// Time Complexity - O(logn) (not nlogn because array already sorted)
// Space Complexity - O(1)
