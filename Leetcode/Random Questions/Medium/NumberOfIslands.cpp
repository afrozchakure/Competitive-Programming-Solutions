class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count += 1;
                    callDFS(grid, i, j);
                }
            }
        return count;
    }
    void callDFS(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        callDFS(grid, i - 1, j); // up
        callDFS(grid, i + 1, j); // down
        callDFS(grid, i, j - 1); // left
        callDFS(grid, i, j + 1); // right
    }
};

// First traverse the matrix and whenever we encounter a '1' convert it to '0' and
// increase the pointer by 1 and change the top, down, right, left values in the matrix
// to '0'