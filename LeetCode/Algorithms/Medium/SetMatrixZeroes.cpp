class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        int col0 = 1;

        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
                col0 = 0;

            // Setting the respective first row and first column to zero, if elememt is 0 at that position
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            // If there are any zeroes in the first column, then set the entire column to zeros
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};

// Time Complexity - O(n*n)
// Space Complexity - O(1), since we are using the same matrix for space