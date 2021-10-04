class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int result = 0;

        int n = grid.size();

        vector<int> max_col_val(n, 0);
        vector<int> max_row_val(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                max_row_val[i] = max(max_row_val[i], grid[i][j]);
                max_col_val[j] = max(max_col_val[j], grid[i][j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result += min(max_row_val[i], max_col_val[j]) - grid[i][j];
            }
        }

        return result;
    }
};