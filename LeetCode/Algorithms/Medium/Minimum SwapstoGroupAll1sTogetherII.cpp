class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(); 
        int total_ones = count(begin(nums), end(nums), 1);
        int max_window_ones = 0, window_ones = 0; 
        
        int l = 0;
        for(int r=0; r<2*n; r++) {
            if(nums[r]) {
                window_ones++; 
            }
            if(r - l + 1 > total_ones) {
                window_ones--; 
                l++;
            }
            max_window_ones = max(max_window_ones, window_ones)
        }
        
    return total_ones - max_window_ones; 
    }
};