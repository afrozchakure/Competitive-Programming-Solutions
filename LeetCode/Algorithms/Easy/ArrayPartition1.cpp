class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        int sum = 0;
        sort(nums.begin(), nums.end());
        // As we have sorted it, we can directly
        // grab the 1st element in each of the pairs
        for (int i = 0; i < nums.size(); i += 2)
        {
            sum += nums[i];
        }
        return sum;
    }
};

// Time Complexity - O(nlogn), Sorting take O(nlog(n)) time
// Space Complexity - O(1), constant extra space used