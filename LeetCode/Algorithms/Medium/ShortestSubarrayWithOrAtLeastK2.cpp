class Solution {
public:
    void updateFreq(vector<int> &bitFreq, int val) {
        for(int i=0; i<32; i++) {
            if(number & (1<<i)) {
                bitFreq[i] += val; 
            }
        }
    }

    int getNumber(vector<int> &bitFreq) {
        int number = 0; 
        long long pow = 1; 
        for(int i =0; i<32; i++) {
            if(bitFreq[i] > 0) {
                number += pow; 
            }
            pow *= 2; 
        }
        return number; 
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        // A ^ B =

        // 0 ^ 0 = 1

        // Find bit value of k

        // find all 

        if(k == 0) {
            return 1; 
        }

        int n = nums.size(); 
        int shortest = INT_MAX;
        int left = 0, right = 0; 
        int currOR = 0; 
        vector<int> bitFreq(32);o 

        while(right < n) {
            updateFreq(bitFreq, nums[right], 1); 
            currOR |= nums[right]; 

            // resize window 
            while(left <= right and currOR >= k) {
                shortest = min(shortest, right - left + 1); 
                updateFreq(bitFreq, nums[left], -1); 
                currOR = getNumber(bitFreq); 
                left++; 
            }
            right++; 
        }
        return shortest == INT_MAX ? -1: shortest; 
    }
};

// Observations 

// 1. 0 or 0 or ... or 0 or 1 = 1
// 2. OR for +ve nos will always be non-decreasing 

// In non-decreasing curve to find smallest subarray use sliding window 

