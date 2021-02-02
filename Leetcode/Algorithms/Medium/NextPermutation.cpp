class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;

        // First scan to find the first number greater than, number on the right
        while (i >= 0 && nums[i + 1] <= nums[i])
        {
            i--;
        }

        if (i >= 0)
        {
            int j = nums.size() - 1;
            // finding the first number greater than number[i], swapping them
            while (j >= 0 && nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums, i, j);
        }

        reverse(nums, i + 1);
    }

    void reverse(vector<int> &nums, int start)
    {
        int i = start, j = nums.size() - 1;
        while (i < j)
        {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

// Time Complexity - O(n), in worst case only two scans of the whole array are needed
// Space Complexity - O(1), no extra space required