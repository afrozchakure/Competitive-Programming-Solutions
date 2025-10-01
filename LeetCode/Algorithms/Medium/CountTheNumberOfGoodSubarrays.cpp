class Solution {
    using ll = long long; 
    public:
        long long countGood(vector<int>& nums, int k) {
            ll n = nums.size(); 
            ll left = 0, right = 0; 
            ll good_subarrays = 0; 
            unordered_map<ll, ll> freq; 
            ll equal_pairs = 0; 

            while(left < n) {
                while(right < n and equal_pairs < k) {
                    freq[nums[right]]++; 
                    if(freq[nums[right]] >= 2) {
                        equal_pairs += freq[nums[right]] - 1; 
                    }
                    right++; 
                }

                if(equal_pairs >= k) {
                    good_subarrays += n - right + 1; 
                }

                // remove left item 
                freq[nums[left]]--; 
                if(freq[nums[left]] > 0) {
                    equal_pairs -= freq[nums[left]];
                }
                left++; 
            }
            return good_subarrays;
      }
};

/*
Time Complexity - O(N)
Space Complexity - O(N)


 0 1 2 3 4 5 6 7 
[1 5 2 5 3 2 5 6]  , K = 2 

[0, 5] = valid 

n = 8 
n - i = 8 - 5 = 3 + 3 = 6 

All Subarrays starting from 0 & ending at idx >= 5 will alwys be valid 

count of equal pairs >= k 

maybe starting at idx > 0 and ending at 5 would also be valid! 

Try for increasing left indices unless the Subarray has count of equals pairs < k 
=> then extend the right end of subarray 

Two pointer and sliding window 

-> Count Equal pairs 

 0 1 2 3 4 5 6 
[1 2 1 1 2 1 2]

f(1) = 4 => 3 + 2 + 1 = 3 * 4 / 2 = 6 

Element | Frequency 
   1        4 
   2        3 

Equal(1, 1) pairs = 4 * 3 / 2 => (n * (n - 1)) / 2
                  = 6 
            
Equal (2, 2) pairs = 3 * 2 / 2 = 3 

Total equal pairs = 6 + 3 = 9


*/