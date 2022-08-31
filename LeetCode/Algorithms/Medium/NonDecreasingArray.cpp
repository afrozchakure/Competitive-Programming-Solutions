// This problem is like a greedy problem. When you find nums[i-1] > nums[i] for some i, you will prefer to change nums[i-1]'s value, since a larger nums[i] will give you more risks that you get inversion errors after position i. But, if you also find nums[i-2] > nums[i], then you have to change nums[i]'s value instead, or else you need to change both of nums[i-2]'s and nums[i-1]'s values.
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        // [4, 2, 3]
        int count = 0; 
        int n = nums.size(); 
        for(int i=1; i<n && count <= 1; i++) {
            if(nums[i-1] > nums[i]) {
                count++; 
                if(i-2 < 0 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];  // modifying nums[i-1]
                else nums[i] = nums[i-1];
            }
        }
        
        return count == 1? true: false; 
    }
};

// Case 1: 
// [1, 7, 3, 4] 
//  Since 1 < 3
//  we replace 7 with 3 

// Case 2: 
// [4, 7, 3, 9]
// since 4 > 3 
// we replace 3 with 9
 