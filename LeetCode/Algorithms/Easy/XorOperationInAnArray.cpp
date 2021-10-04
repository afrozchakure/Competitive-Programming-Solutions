class Solution
{
public:
    int xorOperation(int n, int start)
    {
        vector<int> nums(n, 0);
        int result = start;
        for (int i = 1; i < n; i++)
        {
            nums[i] = start + (2 * i);
            // cout << nums[i] << " " << result << endl;

            result ^= nums[i];
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1), we're using constant space