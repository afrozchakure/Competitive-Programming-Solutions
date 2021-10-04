#include <bits/stdc++.h>
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        if (nums.size() == 0)
            return false;
        sort(nums.begin(), nums.end());           // 4
        for (int i = 0; i < nums.size() - 1; i++) // 0, 1, 2
            if (nums[i] == nums[i + 1])
                return true;
        return false;
    }
};

// Time Complexity - O(logn)
// Space Complexity - O(1)
