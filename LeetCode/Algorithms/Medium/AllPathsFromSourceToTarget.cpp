class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans; 
        int startIndex = 0; 
        int endIndex = graph.size() -1 ; 
        queue<vector<int>> q; 

        q.push(vector<int>{startIndex}); 
        while(!q.empty()) {
            int size = q.size(); 
            while(size-- > 0) {
                vector<int> headList = q.front(); 
                q.pop(); 

                if(headList[headList.size() - 1] == endIndex) {
                    ans.push_back(headList); 
                }
                int lastNode = headList[headList.size() - 1]; 
                for(int connection: graph[lastnode]) {
                    vector<int> copyList(headList.begin(), headList.end()); 
                    copyList.push_back(connection); 
                    q.push(copyList); 
                }
            }
        }
    }
};
// Time Complexity - O(N ** 2) 
// Space Complexity - O(N ** 2)

// Method - 2
class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &paths, int curr) {
        path.push_back(curr); 
        if(curr == graph.size() - 1) {
            paths.push_back(path); 
        } else {
            for(auto it: graph[curr]) {
                dfs(graph, path, paths, it); 
            }
        }
        path.pop_back(); 
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths; 
        vector<int> path; 
        dfs(graph, path, paths, 0); 

        return paths; 
    }
};

// Time Complexity - O(2 ^ N)