class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // use BFS 
        int m = grid.size(), n = grid[0].size(); 
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        bool v[m][n][k+1]; 
        queue<vector<int>> q; 

        q.push({0, 0, k}); 
        int steps = 0; 
        while(!q.empty()) {
            int size = q.size(); 

            while(size-- > 0) {
                vector<int> curr = q.pop(); 
                // If curr is the destination; return steps 
                if(curr[0] == m-1 && curr[1] == n-1) return steps; 
                // Else go in all valid directions 
                for(auto d: DIR) {
                    int i = curr[0] + d[0]; 
                    int j = curr[1] + d[1]; 
                    int obs = curr[2]; 

                    // Traverse through the valid cells 
                    if(i >= 0 && i < m && j >= 0 && j < n) {
                        // If cell is empty visit the cell and add in queue 
                        if(grid[i][j] == 0 && !v[i][j][obs]) {
                            q.push(vector<int>{i, j, obs}); 
                            v[i][j][obs] = true; 
                        } else if(grid[i][j] == 1 && obs > 0 && !v[i][j][obs-1]) {
                            q.push(vector<int>{i, j, obs-1}); 
                            v[i][j][obs-1] = true; 
                        }
                    }
                }
            }
            ++steps; 
        }
        return -1; 
    }
};

// Time Complexity - (M*N*K) 
// Space Complexity - O(M*N*K)

// minimum steps needed to reach bottom right corner? 

// directions: up, down, left, right 
// obstacles: remove max k obstacles

// [0, 0, 1]
// row, col, obstacleBalance

// find all valid directions from current point

// memoization: Store the trio of [i, j, k] as visited / unvisited 

