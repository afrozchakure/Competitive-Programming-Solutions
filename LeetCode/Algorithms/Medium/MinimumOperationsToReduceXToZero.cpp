class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0; 
        int n = nums.size(); 

        for(int i=0; i<n; i++) {
            sum += nums[i]; 
        }

        int start_idx = 0; 
        int curr_sum =0; 
        int target = sum - x; 
        int max_len = 0; 
        for(int end_idx = 0; end_idx < n; end_idx++) {
            curr_sum += nums[end_idx]; 
            while(start_idx <= end_idx && curr_sum > target) {
                curr_sum -= nums[start_idx]; 
                start_idx += 1; 
            }
            if(curr_sum == target) {
                found = true; 
                max_len = max(max_len, end_idx - start_idx + 1); 
            }
        }
        return found ? n - max_len : -1; 
    }
};