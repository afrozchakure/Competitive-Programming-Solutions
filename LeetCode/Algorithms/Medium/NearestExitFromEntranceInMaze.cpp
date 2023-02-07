class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(); 
        int n = maze[0].size(); 

        int level = 0; 
        queue<pair<int, int>> q; 
        maze[entrance[0]][entrance[1]] = '+'; 
        // up - (r-1, c) 
        // down - (r+1, c) 
        // right - (r, c+1) 
        // left - (r, c-1) 
        int dr[4] = {-1, 1, 0, 0}; 
        int dc[4] = {0, 0, -1, 1}; 
        q.push({entrance[0], entrance[1]}); 
        while(!q.empty()) {
            int size = q.size(); 
            level++; 
            for(int i=0; i<size; i++) {
                auto x = q.front(); 
                q.pop(); 
                int row = x.first; 
                int col = x.second; 
                for(int j=0; j<4; j++) {
                    int new_row = row + dr[j]; 
                    int new_col = col + dc[j]; 

                    if(new_row >= 0 && new_col >= 0 && new_row < m && new_col < n) {
                        if(maze[new_row][new_col] == '+') {
                            continue; 
                        }

                        if(new_row == 0 || new_col == 0 || new_row == m-1 || new_col == n-1) {
                            return level; 
                        }
                        q.push({new_row, new_col}); 
                        maze[new_row][new_col] = '+'; 
                    }
                }
            }
        }
        return -1; 
    }
};

// Time Complexity - O(M * N) 
// Space Complexity - O(N), since we're using a queue 