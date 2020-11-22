// Method - 1
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> output_arr(n);

        output_arr[0] = 1;
        for (int i = 1; i < n; i++)
        {
            output_arr[i] = output_arr[i - 1] * nums[i - 1];
        }

        int R = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            output_arr[i] = output_arr[i] * R;
            R = R * nums[i];
        }

        return output_arr;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1), using the answer array
// doesn't add to the space complexity.

// Method - 2
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left_side_product(n);
        vector<int> right_side_product(n);

        left_side_product[0] = 1;
        right_side_product[n - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            left_side_product[i] = left_side_product[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            right_side_product[i] = right_side_product[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] = right_side_product[i] * left_side_product[i];
        }

        return nums;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)