class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rows = 0;
        int cols = 0;

        // Remember base condition should be before
        // the calculation of size()
        if (matrix.size() == 0)
            return vector<int>{};
        vector<int> result;

        int row_start = 0;
        int row_end = matrix.size() - 1;
        int col_start = 0;
        int col_end = matrix[0].size() - 1;

        while (row_start <= row_end && col_start <= col_end)
        {
            // Up
            for (int i = col_start; i <= col_end; i++)
                result.push_back(matrix[row_start][i]);

            row_start++;

            // Right Side
            for (int i = row_start; i <= row_end; i++)
                result.push_back(matrix[i][col_end]);

            col_end--;

            // Down (Here check the conditions for row first)
            if (row_start <= row_end)
            {
                for (int i = col_end; i >= col_start; i--)
                    result.push_back(matrix[row_end][i]);
            }
            row_end--;

            // Left Side (Check the conditions for columns first)
            if (col_start <= col_end)
            {
                for (int j = row_end; j >= row_start; j--)
                {
                    result.push_back(matrix[j][col_start]);
                }
            }
            col_start++;
        }
        return result;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N), N is the number of elements in the matrix