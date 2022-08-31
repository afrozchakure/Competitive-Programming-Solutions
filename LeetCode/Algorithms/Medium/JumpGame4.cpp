class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        /* 
        - For every index starting from 1:  --- n
            - Find out the max sum from all {i-1} to {i - k} index  --- klogk
            - sum[index] = value[index] + maxFound 
        - Result is sum[length - 1]
        */

       int n = nums.size(); 
        int max = nums[0];
       priority_queue<int> pq; 
        for(int i=1; i<n; i++) {
            
        }

    }
};

// Notes: 

