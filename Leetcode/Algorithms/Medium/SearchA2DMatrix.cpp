class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        int rows = matrix.size();
        int columns = matrix[0].size();

        int left = 0;
        int right = (columns * rows) - 1;
        while (left <= right)
        {
            int midpoint = left + (right - left) / 2;
            int midpoint_element = matrix[midpoint / columns][midpoint % columns];

            if (midpoint_element == target)
                return true;
            else if (midpoint_element < target)
                left = midpoint + 1;
            else if (midpoint_element > target)
                right = midpoint - 1;
        }
        return false;
    }
};

// Time Complexity - O(log(m*n)), where m and n are the rows and cols of matrix
// Space Complexity - O(1)