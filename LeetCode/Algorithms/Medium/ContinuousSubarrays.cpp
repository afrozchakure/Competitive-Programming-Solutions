class Solution {
public:
    #define ll long long 

    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size(); 
        int range_min = INT_MAX; 
        int range_max = INT_MIN; 
        int left = 0; 
        int right; 

        ll count = 0; 
        ll win_size; 

        for(right = 0; right < n; right++) {
            range_min = min(range_min, nums[right]); 
            range_max = max(range_max, nums[right]); 

            if((range_max - range_min) > 2) {
                win_size = right - left; 
                count += ((win_size) * (win_size + 1)) / 2;

                left = right; 
                // Expand ranges to current value for right
                range_min = nums[right]; 
                range_max = nums[right];
                
                while(abs(nums[right] - nums[left - 1]) <= 2) {
                    left--; 
                    range_min = min(range_min, nums[left]); 
                    range_max = max(range_max, nums[left]); 
                }
                // Substract overcounted subarrays 
                if(left < right) {
                    win_size = (right - left); 
                    count -= (win_size * (win_size + 1)) / 2;
                }
            }
        }
        // Add subarrays from last window 
        win_size = (right - left); 
        count += ((win_size) * (win_size + 1)) / 2;
        return count; 
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)

// Constraint: In a Subarray: abs(nums[i] - nums[j])  <= 2

// Goal: Count No. of such subarrays

// Generate all possible Subarrays 
// For each Subarray, (max - min) <= 2 
//                       count++; 

// Counting Subarrays 
// No of SAs with size n = (n * (n + 1)) / 2

// [5, 3, 4]
// no. of subarrays = (3 * 4) / 2 = 6

// [5], [5, 3], [5, 3, 4], [3], [3, 4], [4]

// range_max = -inf     , check |max - min| <= 2
// rnage_min = inf 
// win_size = R - L => total ===> count = (total) * (total + 1) / 2
// count = 0

// L -> x you won't know when to STOP

// L = R 
// then <------ L when the 1st out of bound element comes STOP x

// Sliding Window (2 Pointer)

