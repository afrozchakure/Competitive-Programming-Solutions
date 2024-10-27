class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxCount = 0; 
        int n = nums.size(); 
        int maxNum = *max_element(nums.begin(), nums.end()); 

        int left = 0;
        int result = 0; 
        for(int right = 0; right < n; right++) {
            if(nums[right] == maxNum) {
                maxCount += 1; 
            }

            while(maxCount > k || (left <= right && maxCount == k && nums[left] != maxNum)) {
                if(nums[left] == maxNum) {
                    maxCount--; 
                }
                left += 1; 
            }

            if(maxCount == k) {
                result += l + 1; 
            }
        }

        return result; 

        
    }
};


// nums = [1,3,2,3,3], k = 2
//         l     r 


