#define ll long long
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            ll left = 0, right = 0;    // window is [left, right)
            ll sum = 0;         // sum of nums[left ... right -1]
            ll count = 0; 

            ll n = nums.size(); 

            while(left < n) {
                // find larget valid window 
                while(right < n && (sum + nums[right] * (right - left + 1) < k)) {
                    sum += nums[right];
                    right++; 
                }

                // All subarrays starting at 'left' and ending before 'right' are valid 
                count += right - left; 

                // Slide the window forward by removing nums[left] 
                // If we couldn't even include nums[left], move both pointer past it
                if(left == right) {
                    right++; 
                } else {
                    sum -= nums[left];
                }

                left++; 
            }

            return count;
        }
};

/*

Time Complexity - O(N)
Space Complexity - O(1)

Counting Logic 
      0  1  2  3  4  5 
a[]: [2, 1, 1, 3, 4, 1], k = 15 
      |        |  
     start     end

1. Increase end till sum * len < k
2. Count = end - start 
3. Increase start pointer and again when sum * len >= k, 
   calculate count and increment start++ pointer

[start, End) => largest subarray starting at '0' which has (sum * size) < k 

start, end - 1   ie  4 * 3 < 15 

Count of such Subarrays start at '0' = 3 

in general [start, start], [start, start+ 1], ... [start, end-1]

count = end - start 

// Two Pointer + Sliding Window 



*/