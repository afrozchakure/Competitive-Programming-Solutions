class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size();
        int cols = grid1[0].size();
        int count = 0;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid2[i][j] == 1) 
                {
                    count += callDFS(grid1, grid2, i, j);
                }
            }
        }
        return count;
    }
    
    int callDFS(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j)
    {
        int res = 1;
        
        if(i < 0 || j< 0 || i >= grid1.size() || j >= grid1[0].size() || grid2[i][j] == 0)
            return 1;
        
        
        grid2[i][j] = 0;
        
        res &= callDFS(grid1, grid2, i+1, j);  // down 
        res &= callDFS(grid1, grid2, i-1, j);  // up
        res &= callDFS(grid1, grid2, i, j+1);  // right
        res &= callDFS(grid1, grid2, i, j-1);  // down 
        
        return res & grid1[i][j];
    }
};

// Time Complexity - O(mn)
// Space Complexity - O(mn)
