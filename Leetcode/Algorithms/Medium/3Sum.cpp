class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low, high;

        vector<vector<int>> result;
        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                low = i + 1;
                high = n - 1;
                int sum = 0 - nums[i];

                while (low < high)
                {
                    if (nums[low] + nums[high] == sum)
                    {
                        result.push_back({nums[i], nums[low], nums[high]});
                        // Incrementing value of low and high to avoid duplicates
                        while (low < high && nums[low] == nums[low + 1])
                            low++;
                        while (low < high && nums[high] == nums[high - 1])
                            high--;
                        // Incrementing once more to avoid duplicate element
                        low++;
                        high--;
                    }
                    else if ((nums[low] + nums[high]) > sum)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
            }
        }
        return result;
    }
};