// Using Two Pointers method
// We have outer and inner loops, each going through nnn elements.

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        int result = nums[0] + nums[1] + nums[n - 1];

        // Sorting the array to make use of 2 pointer approach
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            int start = i + 1;
            int end = n - 1;

            while (start < end)
            {
                int current_sum = nums[start] + nums[end] + nums[i];

                if (current_sum > target)
                    end--;
                else
                    start++;

                if (abs(current_sum - target) < abs(target - result))
                    result = current_sum;
            }
        }
        return result;
    }
};

// Time Complexity - O(n**2)
// Space Complexity - O(logn) to O(n) depending upon implementation of sorting algorithm