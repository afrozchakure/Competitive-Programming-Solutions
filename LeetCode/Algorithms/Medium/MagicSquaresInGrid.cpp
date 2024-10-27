class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int m = grid.size(); 
        int n = grid[0].size(); 
        int count = 0;
        for(int i=0; i<m-2; i++) {
            for(int j=0; j<n-2; j++) {
                if(magic(i, j, grid)) {
                    count++; 
                }
            }
        }        
        return count; 
    }

    bool magic(int r, int c, vector<vector<int>> &grid) {
        unordered_set<int> set; 

        for(int i=r; i<r+3; i++) {
            for(int j=c; j<c+3; j++) {
                if(set.find(grid[i][j]) != set.end() && !(0 < grid[i][j] && grid[i][j] <= 9)) {
                    return false; 
                } else {
                    set.insert(grid[i][j]); 
                }
            }
        }
        int sum = 0;
        // rows 
        for(int i=r; i<r+3; i++) {
            sum += grid[i + r][c];
        }

        if(sum != 15) {
            return false; 
        }

        // cols 
        int sum = 0;
        for(int j=c; j<c+3; j++) {
            sum += grid[r][j + c];
        }

        if(sum != 15) {
            return false; 
        }

        // diagonals
        sum = grid[r][c] + grid[r+1][c + 1] + grid[r+2][c+2];

        if(sum != 15) return false; 
        sum = 0; 

        sum = grid[r+2][c] + grid[r+1][c+1] + grid[r][c+2];

        if(sum != 15) return false; 
        return true; 

    }
};