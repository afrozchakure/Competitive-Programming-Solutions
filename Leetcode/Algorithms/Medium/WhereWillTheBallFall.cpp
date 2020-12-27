class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> result;
        int rows_start = 0;
        for (int i = 0; i < cols; i++)
        {
            while (rows_start < rows)
            {
            }

            if (grid[0][cols] == 1)
            {
                if (grid[1][cols] == -1)
                {
                    // check(-1) at the bottom left
                    if (grid[rows_start + 1][cols - 1] == 1)
                    {
                    }
                    if (grid[rows_start + 1][cols - 1] == -1)
                    {
                        result.push_back(-1);
                        continue;
                    }
                }
            }
        }
        return result;
    }
};

""
    "
        [1, 1, 1, -1, -1],
    [ 1, 1, 1, -1, -1 ],
    [ -1, -1, -1, 1, 1 ],
    [ 1, 1, 1, 1, -1 ],
    [ -1, -1, -1, -1, -1 ] ""
                           "