// Time Complexity - O(N) , N is the length of nums
// Space Complexity - O(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum_left = 0; 
        int sum_right = 0; 
        int n = nums.size(); 
        sum_right = accumulate(nums.begin() + 1, nums.end(), 0); 
        if(sum_right == 0) {
            return 0; 
        }
        
        for(int i=1; i<n; i++) {
            // cout<<sum_left <<" "<< sum_right<<endl;
            sum_left += nums[i-1];
            sum_right -= nums[i]; 
            if(sum_left == sum_right) {
                // cout<<nums[i]<<" "<<sum_left <<" "<< sum_right<<endl;
                return i;
            }
        }
        return -1; 
    }
};

// Problem - 2 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(); 
        // total sum
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        int left_sum = 0; 
        for(int i=0; i<n; i++) {
            // comparing the right_sum and left_sum
            if(sum - nums[i] - left_sum == left_sum) {
                return i; 
            }
            left_sum += nums[i]; 
        }
        
        return -1; 
    }
};