class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainder = {0 : -1}; 
        // map remainder -> end index 

        int total = 0; 
        for(int i=0; i<nums.size(); i++) {
            total += nums[i]; 
            int r = total % k; 
            if(remainder.find(r) == remainder.end()) {  // if you find 2 totals with same remainder then means that you have found a subarray with sum == k
                remainder[r] = i; 
            } else if(i - remainder[r] > 1) {  
                return true; 
            }
        }
        return false; 

    }
};