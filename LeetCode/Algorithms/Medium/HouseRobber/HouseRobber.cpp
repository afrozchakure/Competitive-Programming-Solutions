class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        
        // [1, 2, 3, 1]
    // [rob1, rob2, n, n+1....]
        
        for(int &element: nums)
        {
            int temp = max(rob1 + element, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        
        return rob2;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1), Dynamic programming 
