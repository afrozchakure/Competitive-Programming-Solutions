class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int result = INT_MAX;
        int n = nums.size();

        int val_sum = 0;
        int left = 0; // our left pointer
        for (int i = 0; i < n; i++)
        {
            val_sum += nums[i];
            while (val_sum >= s)
            {
                result = min(result, i + 1 - left);
                val_sum -= nums[left];
                left++;
            }
        }

        return result != INT_MAX ? result : 0;
    }
};

// Time Complexity - O(n), each node can be visited almost twice,
// once by the right pointer (i) and (almost) once by the left
// pointer
// Space Complexity - O(1), Only constant space is required
// for sum, left and i