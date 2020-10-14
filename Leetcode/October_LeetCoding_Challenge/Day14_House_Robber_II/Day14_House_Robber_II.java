class Solution {
    public int rob(int[] nums) {
       if(nums.length == 0)
           return 0;
        if(nums.length == 1)
            return nums[0];
        int[] dp = new int[nums.length + 1]; // start from first house
        int[] secdp = new int[nums.length +1]; /// start from second house
        
        dp[0] = 0;
        dp[1] = nums[0];
        
        secdp[0] = 0;
        secdp[1] = 0;
        
        for(int i= 2;  i <= nums.length ; i++){
            dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i-1]);
            secdp[i] = Math.max(secdp[i-1], secdp[i-2] + nums[i-1]);
            
        }
        return Math.max(dp[nums.length-1], secdp[nums.length]);
        
    }
}
