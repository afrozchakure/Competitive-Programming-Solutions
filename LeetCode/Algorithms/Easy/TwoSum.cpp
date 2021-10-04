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

// Method - 2 (Naive Approach)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        int start = 0, end =0;
        for(int i=0; i<n; i++)
        {
            int find = target - nums[i];
            for(int j=i+1; j<n; j++)
            {
                if(nums[j] == find)
                {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>{};
    }
};

// Time Complexity - O(N**2)
// Space Complexity - O(1)
