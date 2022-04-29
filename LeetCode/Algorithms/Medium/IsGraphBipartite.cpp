class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 
        queue<int> q; 
        vector<int> color(n, 0);
        
        for(int i=0; i<n; i++) {
            if(color[i]) continue; 
            
            q.push(i); 
            color[i] = 1; 
            
            while(!q.empty()) {
                int parent = q.front();
                q.pop(); 
                
                for(int child: graph[parent]) {
                    if(color[child] == 0) {
                        color[child] = -color[parent]; 
                        q.push(child); 
                    }
                    else if(color[parent] == color[child]) {
                        return false; 
                    }
                }
            }
        }
        return true; 
    }
};

// Time Complexity - O(N*N)
// Space Complexity - O(N), since we're using a queue and color vector 
// Refer Naman_Rathod's solution
