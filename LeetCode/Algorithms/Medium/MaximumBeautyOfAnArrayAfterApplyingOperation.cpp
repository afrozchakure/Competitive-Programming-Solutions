class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 

        int n = nums.size(); 
        int win_count = 0; 
        int max_count = 0; 

        int left = 0, right = 0; 
        while(right < n) {
            // find valid window of max size 
            while(right < n && (nums[right] - nums[left] <= 2 * k)) {
                win_count++; 
                right++; 
            }

            max_count = max(max_count, win_count); 
            if(right == n) break;

            // skip left to again make window vlaid 
            while(left <= right && (nums[right] - nums[left] > 2 * k)) {
                win_count--; 
                left++; 
            }
        }
        return max_count; 
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(1)