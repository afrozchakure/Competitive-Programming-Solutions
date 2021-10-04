class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            // abs() is needed to avoid overflow condition
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0)
                nums[index] = nums[index] * (-1);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                result.push_back(i + 1);
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1) --> Given that returned list does not count as extra space