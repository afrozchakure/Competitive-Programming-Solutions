class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int ans = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans += 4;

                    if (i + 1 < rows && grid[i + 1][j] == 1)
                        ans--;
                    if (i - 1 >= 0 && grid[i - 1][j] == 1)
                        ans--;
                    if (j + 1 < cols && grid[i][j + 1] == 1)
                        ans--;
                    if (j - 1 >= 0 && grid[i][j - 1] == 1)
                        ans--;
                }
            }
        }
        return ans;
    }
};

// Time Complexity - O(m x n), m is the rows and n is the cols
// Space Complexity - O(1)