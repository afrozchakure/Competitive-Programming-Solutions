class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0)
        {
            n &= (n-1);
            count++;
        }
        return count;
    }
};

// Time Complexity - O(n)   // n is no. of 1 in the number 
// Space Complexity - O(1)
