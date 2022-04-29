#define pii pair<int, pair<int, int>> 
class Solution {
public: 
    // Directions (top, right, bottom, left) 
    const int d4x[4] = {-1, 0, 1, 0}, d4y[4] = {0, 1, 0, -1}; 

    int minimumEffortPath(vector<vector<int>>& heights) {
        // Djitra's shortest path 
        int n = heights.size();  // rows 
        int m = heights[0].size();  // cols 

        // min-heap 
        priority_queue<pii, vector<pii>, greater<pii>> pq; 
        // to store distances from (0, 0) 
        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));   
        dis[0][0] = 0; 
        pq.push({0, {0, 0}}); 

        // Dijstra's algorithm 
        while(!pq.empty()) {
            pii curr = pq.top(); pq.pop(); 
            int d = curr.first, r = curr.second.first, c = curr.second.second; 

            // bottom right position 
            if(r == n-1 && c == m - 1) return d; 
            for(int i=0; i<4; i++) {
                int nx = r + d4x[i], ny = c + d4y[i]; 
                // check if new postion is invalid 
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
                int nd = max(d, abs(h[nx][ny] - h[r][c])); 
                if(nd < dis[nx][ny]) {
                    dis[nx][ny] = nd; 
                    pq.push({nd, {nx, ny}}); 
                }
            }
        }
        return 0; 
    }
};