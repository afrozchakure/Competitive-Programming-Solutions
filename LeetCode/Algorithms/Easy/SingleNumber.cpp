// Using XOR operation a xor a xor b => 0 xor b => b
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int a = 0;
        for (int i = 0; i < nums.size(); i++)
            a = a ^ nums[i];
        return a;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)

// Using unordered_map
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end())
                m[nums[i]] += 1;
            else
                m[nums[i]] = 1;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (m[nums[i]] == 1)
                return nums[i];
        }
        return -1;
    }
};

// Time Complexity - O(n), n is number of elements in the vector
// Space Complexity - O(n)