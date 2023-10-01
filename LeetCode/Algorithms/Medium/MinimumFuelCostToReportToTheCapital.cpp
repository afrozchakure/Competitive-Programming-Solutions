class Solution {
public:
    long long fuel = 0; 
    int s;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        s = seats; 

        vector<vector<int>> graph(roads.size() + 1); 

        for(auto &road: roads) {
            graph[road[0]].push_back(road[1]); 
            graph[road[1]].push_back(road[0]); 
        }
        dfs(0, 0, graph); 
        return fuel; 
    }

    int dfs(int currCity, int prevCity, vector<vector<int>> &graph) {
        int people = 1; 

        for(auto &nextCity: graph[currCity]) {
            if(nextCity == prevCity) {
                continue; 
            }
            people += dfs(nextCity, currCity, graph); 
        }

        if(currCity != 0) {
            fuel += ceil((double)people / s);
        }
        return people;
    }
};

// TC - O(N) 
// SC - O(N)