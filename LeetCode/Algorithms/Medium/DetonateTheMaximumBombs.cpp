class Solution {
    public:


        int maximumDetonation(vector<vector<int>>& bombs) {
            
            vector<vector<int>> adj(bombs.size()); 

            for(int i=0; i<bombs.size(); i++) {
                for(int j=i + 1; j<bombs.size(); j++) {
                    auto &temp = bombs[i]; 
                    int x1 = temp[0]; 
                    int y1 = temp[1]; 
                    int r1 = temp[2]; 

                    auto &temp2 = bombs[j]; 
                    int x2 = temp2[0]; 
                    int y2 = temp2[1]; 
                    int r2 = temp2[2]; 

                    int d = sqrt((x1 - x2)**2 + (y1 - y2)**2);

                    if(d <= r1) {
                        adj[i].push_back(j);   // bomb at index i can detonate bomb at index j 
                    }
                    if(d <= r2) {
                        adj[j].push_back(i);  // bomb at index j can detonate bomb at index i 
                    }
                }
            }

            int result = 0; 
            unordered_set<int> set; 
            for(int i=0; i<bombs.size(); i++) {
                
                result = max(res, dfs(i, visit)); 
            }
        }

        dfs(int i, unordered_set<int> &visit) {
            if(visit.find(i) != visit.end()) {
                return 0; 
            }

            visit.insert(i); 
            for(auto nei: adj[i]) {
                dfs(nei, visit); 
            }
            return len(visit); 
        }
    };