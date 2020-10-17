class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> temp;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];

            // if diff is in the map temp, we simply return the indexes saved in temp
            // and current index
            if (temp.find(diff) != temp.end())
            {
                result.push_back(temp[diff]);
                result.push_back(i);
                return result;
            }
            else
            // if temp not in nums[i]
            {
                temp[nums[i]] = i;
            }
        }
        return result;
    }
};