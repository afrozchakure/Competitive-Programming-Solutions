class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();  // 3
        int j = 0;
        for(int i=0; i<n; i++){  // 0,1,2
            if(i < n-1 && nums[i] == nums[i+1])   // If two values are same, then continue the loop, don't update
                continue;
            nums[j++] = nums[i];  // Not add value into this
        }
        return j; // Returns the length of array
    }
};
