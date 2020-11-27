class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {

        if (grid.size() == 0)
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        // Grid keeps track of minimum sum, to reach an element
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // first add the number at that position
                dp[i][j] = grid[i][j];

                // if both i & j are greater than 0, add the minimum value to grid
                if (i > 0 && j > 0)
                {
                    dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]); // remember we take minimum of dp's rows and cols
                }                                                // else add either one
                else if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j];
                }
                else if (j > 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        // return the last row and last col element, as answer
        return dp[rows - 1][cols - 1];
    }
};

// Time complexity - O(n*m)
// Space Complexity - O(n*m)
