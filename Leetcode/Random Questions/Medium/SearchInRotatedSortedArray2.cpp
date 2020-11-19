class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            if (nums[left] == target || nums[right] == target)
                return true;
            else if (nums[left] < target)
            {
                // to skip the duplicate values
                while (left < right && nums[left] == nums[left + 1])
                {
                    left++;
                }
                left++;
            }

            else if (nums[right] > target)
            {
                {
                    while (left < right && nums[right - 1] == nums[right])
                        right--;
                }
                right--;
            }
            else
            {
                break;
            }
        }
        return false;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)