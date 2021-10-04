#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> map = {{0, 1}};

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (map.find(sum - k) != map.end())
                count += map[sum - k];
            map[sum]++;
        }
        return count;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)