// Floyd's Tortoise and Hare (Cycle Detection)

#include <bits/stdc++.h>
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        int a_pointer = nums[0];
        int b_pointer = slow;

        while (a_pointer != b_pointer)
        {
            a_pointer = nums[a_pointer];
            b_pointer = nums[b_pointer];
        }
        return a_pointer;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)