// Method - 1
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        for(int i=0; i<n; i++)
        {
            result.push_back(nums[i]);
            result.push_back(nums[n+i]);
        }
    return result;
    }
};

// Time Complexity - O(n) - For loop with n time
// Space Complexity - O(n) -- Creating a vector with 2n space
