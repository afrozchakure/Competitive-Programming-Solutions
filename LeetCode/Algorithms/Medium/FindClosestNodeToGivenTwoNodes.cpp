class Solution {
    public:
        int closestMeetingNode(vector<int>& edges, int node1, int node2) {
            int n = edges.size(); 
            vector<vector<int>> adj(n); 
            
            // some of the destination nodes can be -1
            // it would also get added in the distance map in bfs traversal 
            // it won't affect our result because we are traversing 
            // from 0 to n indexes only 
            for(int i=0; i<edges.size(); i++) {
                adj[i].push_back(edges[i]); 
            }

            unordered_map<int, int> node1Dist;  // map node -> distance from node1
            unordered_map<int, int> node2Dist;  // map node -> distance fromm node2

            bfs(node1, node1Dist, adj); 
            bfs(node2, node2Dist, adj);
            
            int res = -1; 
            int resDist = INT_MAX; 

            for(int i=0; i<n; i++) {
                if(node1Dist.count(i) && node2Dist.count(i)) {
                    dist = max(node1Dist[i] node2Dist[i]);
                    if(dist < resDist) {  // we have to take the smallest distance node and return the result node 
                        res = i; 
                        resDist = dist; 
                    }
                }
            }
            return res; 
        }

        void bfs(int src, unordered_map<int, int> distMap, vector<vector<int>> &adj) {
            queue<pair<int, int>> q; 
            q.push({src, 0}); 
            distMap[src] = 0; 
            while(!q.empty()) {
                auto temp = q.front(); 
                int node = temp.first; 
                int dist = temp.second; 

                for(auto &nei: adj[node]) {
                    if(distMap.find(i) == distMap.end()) {
                        q.push({nei, dist + 1}); 
                        distMap[nei] = dist + 1;
                    }
                }
            }
        }
    };