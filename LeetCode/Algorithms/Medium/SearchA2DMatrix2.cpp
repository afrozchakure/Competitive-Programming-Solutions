class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = cols - 1;

        while (left < rows && right >= 0)
        {
            int mid_element = matrix[left][right];

            if (mid_element == target)
                return true;
            if (mid_element < target)
                left++;
            if (mid_element > target)
                right--;
        }

        return false;
    }
};

// Time Complexity - O(log(m*n)), where m and n are rows and columns of matrix
// Space Complexity - O(1), constant space