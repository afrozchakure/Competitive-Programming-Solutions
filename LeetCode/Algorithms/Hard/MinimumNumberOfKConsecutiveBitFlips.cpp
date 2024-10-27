class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
       // 1. Start window at 0, has to be size k 
       // 2. flip, some might turn into 0's 
       // 3. start window there 

        deque<int> q; 
        int result = 0; 

        for(int i=0; i<nums.size(); i++) {
            if((nums[i] + q.size()) % 2 == 0) {
                if(i + k > nums.size()) {
                    return -1; 
                }
                result += 1; 
                q.push_back(i); 
            }
        }   

        return result;  
    }
};