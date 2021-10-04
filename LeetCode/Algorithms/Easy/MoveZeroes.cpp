class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int first_zero = 0;
        int first_non_zero = 0;

        while (first_non_zero < n)
        {
            if (nums[first_non_zero] == 0)
            {
                first_non_zero++;
            }
            else
            {
                int temp = nums[first_non_zero];
                nums[first_non_zero] = nums[first_zero];
                nums[first_zero] = temp;
                first_zero++;
                first_non_zero++;
            }
        }
    }
};

// Time Complexity - O(n)
// The total operations (array writes) that code does is Number of non-0 elements.
// This gives us a much better best-case (when most of the elements are 0) complexity than last solution.
// Space Complexity - O(1)

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int lastNonZeroFoundAt = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] != 0)
                nums[lastNonZeroFoundAt++] = nums[i];
        for (int i = lastNonZeroFoundAt; i < n; i++)
            nums[i] = 0;
    }
};

// Time Complexity - O(n)
// However, the total number of operations are still sub-optimal.
// The total operations (array writes) that code does is nnn (Total number of elements).

// Space Complexity - O(1)