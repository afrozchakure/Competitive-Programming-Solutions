// Method - 1
class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int start = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                if (start != -1 && i - start - 1 < k)
                    return false;
                start = i;
            }
        }
        return true;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)

// Method - 2
class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int start = -1;
        int end = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1 && start == -1)
            {
                start = i;
            }
            else if (nums[i] == 1 && end == -1)
            {
                end = i;
            }
            if (start != -1 && end != -1 && (end - start - 1) < k)
            {
                return false;
            }
            if (start != -1 && end != -1)
            {
                int temp = start;
                start = end;
                end = -1;
            }
        }
        return true;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)