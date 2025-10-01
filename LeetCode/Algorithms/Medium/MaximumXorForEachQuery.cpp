class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(); 
        vector<int> result(n, 0); 
        int xor = 0; 

        for(auto &n: nums) {
            xor ^= n; 
        }

        int mask = pow(2, maximumBit) - 1

        for(int i=n-1; i>=0; i--) {
            result.push_back(xor ^ mask);

            // remove the last element each time 
            xor ^= nums[i];  
        }

        return result;       
    }
};