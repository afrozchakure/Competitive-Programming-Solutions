class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right)
        {
            int mid = left + (right -left) / 2;
            
            if(nums[mid] < nums[mid + 1])
            {
                left = mid + 1;
            }
            else 
            {
                right = mid;
            }
        }
        return left;
    }
};
// Time Complexity - O(logN), since everytime we find our left pointer less than next pointer we increment left to mid + 1, also the problem wants us to find any peak... so it is similar to find peak index problem
// Space Complexity - O(1)
