
// Brute Force Appraoch
// Traversing the whole array and whenever we find a zero
// Set the corresponding rows and column elements to -1 expect the ones which are zero.
// In the end traverse whole array and whereever there is -1 set it to 0
// Time Complexity - O((N x M) x (N + M))
// Space Complexity - O(1)

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        int col0 = 1; // its the value in the top left corner
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
                col0 = 0;
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
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};

// Time Complexity - O(N*M)
// Space Complexity - O(1)