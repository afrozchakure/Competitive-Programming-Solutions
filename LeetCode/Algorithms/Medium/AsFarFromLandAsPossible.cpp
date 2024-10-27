// DFS solution - gives Time Limited exeeded
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // 0 - water 
        // 1 - land 

        int rows = grid.size(); 
        int cols = grid[0].size(); 
        for(auto i=0; i<rows; i++) {
            for(auto j=0; j<cols; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0; 
                    dfs(grid, i, j); 
                }
            }
        }

        int mx = -1; 
        for(auto i=0; i<rows; i++) {
            for(auto j=0; j<cols; j++) {
                if(grid[i][j] > 1)
                    mx = max(mx, grid[i][j] - 1); 
            }
        }
        return mx; 
    }

    void dfs(vector<vector<int>> &grid, int i, int j, int dist = 1) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || (grid[i][j] != 0 && grid[i][j] <= dist)) return; 

        grid[i][j] = dist; 

        // up 
        dfs(grid, i-1, j, dist + 1); 
        // down 
        dfs(grid, i+1, j, dist + 1); 
        // left 
        dfs(grid, i, j-1, dist + 1); 
        // right
        dfs(grid, i, j+1, dist + 1); 
    }
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return -1; 
        }
        int row = grid.size(); 
        int col = grid[0].size(); 
        vector<vector<bool>> visited(row, vector<bool>(col, false)); 
        return bfs(grid, visited, grid.size(), grid[0].size());
    }

    int bfs(vector<vector<int>>& grid, vector<vector<bool>> visited, int row, int col) {
        queue<pair<int, int>> queue; 
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; 
        int result = -1; 
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == 1) {
                    visited[i][j] = true; 
                    queue.push(make_pair(i, j));
                }
            }
        }

        while(!queue.empty()) {
            int size = queue.size(); 

            while(size-- > 0) {
                pair<int, int> current = queue.front(); 
                queue.pop(); 

                int x = current.first; 
                int y = current.second; 
                for(auto &dir: directions) {
                    int newX = dir[0] + x;
                    int newY = dir[1] + y;

                    if(newX < 0 || newY < 0 || newX >= row || newY >= col || visited[newX][newY]) {
                        continue; 
                    }
                    visited[newX][newY] = true; 
                    grid[newX][newY] = grid[x][y] + 1; 
                    result = max(result, grid[newX][newY]); 
                    queue.push(make_pair(newX, newY)); 
                }
            }
        }
        return result < 0 ? -1 : result - 1; 
    }
};