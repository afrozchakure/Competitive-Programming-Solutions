class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int totalSum = 0; 

        for(auto &num: nums) {
            totalSum = (totalSum + num) % p;
        }
        
        int remain = totalSum % p; 
        if(remain == 0) {
            return 0; 
        }
        unordered_map<int, int> modMap;
        modMap[0] = -1;

        int result = nums.size(); 

        int currentSum = 0; 
        for(int i=0; i<nums.size(); i++) {
            currentSum = (currentSum + nums[i]) % p;
            int needed = (currentSum - remain + p) % p;

            if(modMap.find(needed) != modMap.end()) {
                int length = i - modMap[needed];
                result = min(result, length);
            }
            modMap[currentSum] = i;
        }

        if(result == nums.size()) {
            return -1; 
        }
        return result;
    }
};