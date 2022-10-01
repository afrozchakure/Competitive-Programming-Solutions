class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0; 
        
        int left = 0;
        int right = 0; 
        
        while(right < nums.size() - 1) {
            int farthest = 0; 
            for(int i=left; i<=right; i++) {
                farthest = max(farthest, nums[i] + i); 
            }
            left = right + 1; 
            right = farthest; 
            result += 1; 
        }
        
        return result; 
    }
};

// Time Complexity - o(N) 
// Space complexity - O(1)