/*
The 2 requirements of the question are:

1. Move all the 0's to the end of array.
2. All the non-zero elements must retain their original order.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Space Sub-Optimal
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
          
        // Count the zeros
        int count = 0;
        for(int i=0; i<n; i++)
            if(nums[i] == 0)
                count += 1;
        
        // Make all the non zeros elements retain their order
        vector <int> second;
        for(int i=0; i<n; i++)
            if(nums[i] != 0)
                second.push_back(nums[i]);

        // Move all zeros to the end
        while(count--)
            second.push_back(0);
        
        // Combine the result
        for(int i=0; i<n;i++)
            nums[i] = second[i];
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)

// Method - 2 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int lastNonZeroFoundAt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0)
                nums[lastNonZeroFoundAt++] = nums[i];
        }
        for(int i=lastNonZeroFoundAt; i<n; i++)
            nums[i] = 0;
    }
};

// Time Complexity - O(n) - n is total no. of elements
// Space Complexity - O(1) - Constant space is used