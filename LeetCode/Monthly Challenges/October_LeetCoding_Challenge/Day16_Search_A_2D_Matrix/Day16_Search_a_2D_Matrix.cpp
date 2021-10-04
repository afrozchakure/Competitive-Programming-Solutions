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
        int right = rows * columns - 1;

        while (left <= right)
        {
            int midpoint = left + (right - left) / 2; // Remember this method to find middle elements
            int midpoint_element = matrix[midpoint / columns][midpoint % columns];
            if (midpoint_element == target)
                return true;
            if (midpoint_element > target)
                right = midpoint + 1;
            if (midpoint_element < target)
                left = midpoint - 1;
        }
    }
};