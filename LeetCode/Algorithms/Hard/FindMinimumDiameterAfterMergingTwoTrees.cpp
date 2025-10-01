class Solution {
public:
    int diameter(unordered_map<int, vector<int>>& adj, int n) {
        // pick any node and find the farthest from that node
        vector<bool> visited(n, false);
        queue<int> q; 
        q.push(0); 
        visited[0] = true;
        int last;
        while(!q.empty()) {
            int size = q.size(); 
            for(int i=0; i<size; ++i) {
                last = q.front(); 
                q.pop(); 

                visited[last] = true; 
                for(int ele: adj[last]) {
                    if(!visited[ele]) {
                        q.push(ele); 
                    }
                }
            }
        }

        // Now find the farthest node from here and hop == diameter 
        q.push(last);
        int hop = 0; 
        vector<int> vis(n, false); 
        vis[last] = true;
        while(!q.empty()) {
            int size = q.size(); 
            for(int i=0; i<size; ++i) {
                int curr = q.front(); 
                q.pop(); 

                vis[curr] = true; 
                for(int ele: adj[curr]) {
                    if(!vis[ele]) {
                        q.push(ele); 
                    }
                }
            }
            hop += 1; 
        } 
        return hop-1; 
    }

    int findDiameter(vector<vector<int>>& edges) {
        if(edges.size() == 0) {
            return 0; 
        }

        unordered_map<int, vector<int>> adj; 
        unordered_set<int> nodes; 

        for(auto &edge: edges) {
            cout<<edge[0]<<" "<<edge[1]<<endl;
            adj[edge[0]].push_back(edge[1]); 
            adj[edge[1]].push_back(edge[0]); 
            nodes.insert(edge[0]); 
            nodes.insert(edge[1]); 
        }

        return diameter(adj, nodes.size()); 
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int dia1 = findDiameter(edges1); 
        int dia2 = findDiameter(edges2); 

        int radius1 = (dia1 + 1) / 2; 
        int radius2 = (dia2 + 1) / 2; 
        int sum = 1 + radius1 + radius2;  

        return max(sum, max(dia1, dia2)); 
    }
};

// Time Complexity - O(N + M)
// Space Complexity - O(N + M)

// Follow-up 
// 1. Prove the greedy algo.
// 2. Find al diameters of a tree 

// How to find optimal path? 

// Note: It is always optimal to join at midpoint of diameter

// total height = h1 / 2 + bridge (1) + h2 / 2

// Cases 

// Even-Even ==> ans = 1 + dia1 / 2 + dia2 / 2 
// Odd-Even ==> ans = 1 + (dia1 + 1) / 2 + dia2 / 2
// Odd-Odd ==> ans = 1 + (dia1 + 1) / 2 + (dia2 + 1) / 2

// How to find diameter of undirected tree?
// Greedy Algorithm 
// 1. Choose any node (a)
// 2. Find farthest node from a (b) --> BFS(levelorder)
// 3. Find farthest node from b and count no. of hops / levels 
//       diameter = no. of hops 

// Case 1: Your chosen node is already on diameter 

// Joining may not always contain diameter 

// max diameter = max{dia1, dia2, 1 + (dia1 + 1) / 2 + (dia2 + 1) / 2}


