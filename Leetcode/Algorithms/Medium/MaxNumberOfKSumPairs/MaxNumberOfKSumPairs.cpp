class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums.size() - 1;
        int count = 0;
        while (start < end)
        {
            int val = nums[start] + nums[end];
            if (val > k)
                end--;
            else if (val < k)
                start++;
            else if (val == k)
            {
                start++;
                end--;
                count++;
            }
        }
        return count;
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(1)