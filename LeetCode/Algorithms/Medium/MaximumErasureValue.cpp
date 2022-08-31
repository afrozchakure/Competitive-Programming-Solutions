class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> set; 
        int n = nums.size(); 
        int curr_sum = 0; 
        int total_sum = 0; 
        int i = 0; 
        for(int j=0; j<n; j++) {
            // this will remove all values from the set
            while(set.find(nums[j]) != set.end()) {
                set.erase(nums[i]); 
                curr_sum -= nums[i]; 
                i++;
            }
            set.insert(nums[j]);
            curr_sum += nums[j]; 
            total_sum = max(curr_sum, total_sum);
        }
        return total_sum;
    }
};

// Refer @r0gue_shinobi's solution

