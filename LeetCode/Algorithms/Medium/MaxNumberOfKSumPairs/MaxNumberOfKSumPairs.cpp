// - Method - 1  (Use M2 for space efficient solution and M1 for time efficient solution) 
// - Time Complexity - O(N) 
// - Space Complexity - O(N) 

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap; 
        int n = nums.size(); 
        int ans = 0; 
        for(int i=0; i<n; i++) {
            if(freqMap[k - nums[i]] > 0) {
                freqMap[k - nums[i]]--; 
                ans++; 
            } else {
                freqMap[nums[i]]++; 
            }
        }
        return ans; 
    }
};

// ------------------------
// -  Method - 2 
// -  Time Complexity - O(NLogN) 
// -  Space Complexity - O(1) 

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int start =0; 
        int end = nums.size() - 1; 
        int ans = 0; 
        
        sort(nums.begin(), nums.end()); 
        
        while(start < end) {
            int sum = nums[start] + nums[end]; 
            
            if(sum == k) {
                start++; 
                end--; 
                ans++; 
            } else if(sum < k) {
                start++; 
            } else if(sum > k) {
                end--; 
            }
        }
        
        return ans; 
    }
};