/*
Things to remember (^ is a XOR operator in cpp)-

We know, X^X = 0 , Y^0 = Y

We create the second list using i and first list using nums[i]
(A1, A3, A4) ^ (A1, A2, A3, A4)

Since XOR operation is associative
(A1 ^ A1) ^ A2 ^ (A3 ^ A3) ^ (A4 ^ A4) which gives A2 as result

*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        
        // xor's all the elements
        for(int i=0; i<nums.size(); i++)
            result ^= nums[i];
        
        // xor's from 1 to n
        for(int i=0; i<=nums.size(); i++)
            result ^= i;
        
        return result;    
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)
