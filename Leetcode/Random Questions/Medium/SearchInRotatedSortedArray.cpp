class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int right = nums.size() - 1;
        int left = 0;

        while (left <= right)
        {
            if (nums[left] == target || nums[right] == target)
            {
                if (nums[left] == target)
                    return left;
                else
                    return right;
            }
            else if (nums[left] < target)
                left++;
            else if (nums[right] > target)
                right--;
            else
                break;
        }
        return -1;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)