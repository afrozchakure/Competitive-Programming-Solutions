class Solution {
public:
    #define pi pair<int, pair<int, int>> 

    bool isValid(int &x, int &y, int &m, int &n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(); 
        int n = heightMap[0].size(); 

        if(m < 3 && n < 3) {
            return 0; 
        }

        // Step-1: Push all boundary elements as START points 
        priority_queue<pi, vector<pi>, greater<pi>> minheap;
        vector<vector<int>> visited(m, vector<bool>(n, false));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 || j == 0 || j == m-1 || i == n-1) {
                    visited[i][j] = true;
                    minheap.push(make_pair(heightMap[i][j], make_pair(i, j))); 
                }
            }
        }

        // Step-2: Apply BFS similar to level order traversal 
        int trapped_water = 0; 
        int level = 0; 
        vector<int> dir = {-1, 0, 1, 0, -1}; // URDL 4-dir calls
        while(!minheap.empty()) {
            pi curr = minheap.top(); 
            minheap.pp(); 

            int height = curr.first; 
            int x = curr.second.first; 
            int y = curr.second.second; 
            level = max(level, height); 

            // 4-directional traversal
            for(int i=0; i<4; i++) {
                int newX = x + dir[i]; 
                int newY = x + dir[i + 1]; 
                if(isValid(newX, newY, m, n) && !visited[newX][newY]) {
                    visited[newX][newY] = true; 
                    minheap.push(make_pair(heightMap[newX][newY], make_pair(newX, newY)));
                    if(heightMap[newX][newY] < level) {
                        trapped_water += level - heightMap[newX][newY];
                    }
                }
            }
        }
        return trapped_water;
    }
};

// Time Complexity - O(M * N * log(M * N)), log(M * N) is the heap arrangement, 
// M * N is Total Cells
// Space Complexity - O(M * N), visited array min heap

