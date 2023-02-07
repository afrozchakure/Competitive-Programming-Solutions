class Solution {
public:
    unordered_map<int, vector<int>> graph; 
    unordered_map<int, int> color; 
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        for(int i=1; i<=n; i++) {
            graph[i] = vector<int> {}; 
        }

        for(auto edge: dislikes) {
            graph[edge[0]].push_back(edge[1]); 
            graph[edge[1]].push_back(edge[0]);
        }

        for(int node = 1; node <= n; node++) {
            if(!color.containsKey(node) && !dfs(node, 0)) {
                return false; 
            }
        }
        return true; 
    }
    bool dfs(int node, int c) {
        if(color.find(node) != color.end()) {
            return color[node] == c; 
        }
        color[node] = c; 
        cout<<node<<" "<<c<<endl; 
        for(int nei: graph[node]) {
            if(!dfs(nei, c ^ 1)) {
                return false; 
            }
        }
        return true; 
    }
};