// Method 1
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = 1;
        int result = 0;
        while (right < nums.size())
        {
            int diff = nums[right] - nums[left];
            if (diff == 1)
            {
                result = max(result, right - left + 1);
            }

            if (diff <= 1)
            {
                right++;
            }
            else
            {
                left++;
            }
        }
        return result;
    }
};

// Time Complexity - O(NlogN), as we are sorting
// Space Complexity - O(1)

// Method 2
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> map;

        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        for (auto i : map)
        {
            // First check the count of previous element to i, if it exists
            if (map.count(i.first - 1) > 0)
            {
                result = max(result, i.second + map[i.first - 1]);
            }
        }
        return result;
    }
};

// Time Complexity - O(N)
// Space Complexiy - O(N)
