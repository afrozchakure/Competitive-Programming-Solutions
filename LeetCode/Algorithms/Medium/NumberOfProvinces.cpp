class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); 
        // vector<vector<int>> adjList(n, vector<int>)
        vector<int> adjList[n];

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j); 
                    adjList[j].push_back(i); 
                }
            }
        }

        int visited[n] = {0}; 
        int count = 0; 
        for(int i=0; i<n; i++) {
            if(!visited) {
                count++; 
                dfs(i, adjList, visited); 
            }
        } 

        return count; 
    }

    void dfs(int node, vector<int> adjList[], int visited[]) {
        visited[node] = 1; 

        for(auto it: adjList[node]) {
            if(!visited[it]) {
                dfs(it, adjList, visited); 
            }
        }
    }
};

// Space Complexity - O(N) (visited array) + O(N) (recurssion stack space)
// not taking adjacency list into account 

// Time Complexity - O(N) + O(V + 2E) 
            //    ~ O(N) (equivalent to)