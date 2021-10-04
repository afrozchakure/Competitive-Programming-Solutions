#include <vector>
class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        vector<int> result;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (!result.empty() && result.back() > nums[i] && (result.size() - 1 + nums.size() - i >= k))
                result.pop_back();
            if (result.size() < k)
                result.push_back(nums[i]);
        }
        return result;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

// See lee's solution