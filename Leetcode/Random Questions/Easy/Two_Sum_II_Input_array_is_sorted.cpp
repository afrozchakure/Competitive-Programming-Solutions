class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int a_pointer = 0;
        int b_pointer = nums.size() - 1;
        while (a_pointer <= b_pointer)
        {
            int sum = nums[a_pointer] + nums[b_pointer];
            if (sum > target)
                b_pointer -= 1;
            else if (sum < target)
                a_pointer += 1;
            else if (sum == target)
            {
                return vector<int>{a_pointer + 1, b_pointer + 1};
            }
        }
        return vector<int>{a_pointer + 1, b_pointer + 1};
    }
};

// When the array is sorted think of using pointers