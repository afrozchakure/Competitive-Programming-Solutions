class Solution {
public:
   int maxProfit(vector<int>& nums){
       int sum = 0;
       int n = nums.size(); 
       for(int i=0; i<n; i++){
           if(i < n-1 && nums[i+1] > nums[i])
                sum += nums[i+1] - nums[i];
       }
       return sum;
   }
};

// Time Complexity - O(N)
// Space Complexity - O(1)
