class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        if (nums.size() == 0)
            return {-1, -1};

        vector<int> result;

        int set = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                result.push_back(i);
                set = 1;
                break;
            }
        }

        if (set == 0)
            return {-1, -1};

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] == target)
            {
                result.push_back(i);
                break;
            }
        }

        return result;
    }
};
// Time Complexity - O(n), worst case we need to traverse the whole array twice
// Space Complexiy - O(1)