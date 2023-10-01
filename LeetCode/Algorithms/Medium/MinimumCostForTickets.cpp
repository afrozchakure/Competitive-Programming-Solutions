class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs, int cost = 0) {
        queue<pair<int, int>> last7, last30; 

        for(auto d: days) {
            while(!last7.empty() && last7.front().first + 7 <= d) {
                last7.pop(); 
            }  
            while(!last30.empty() && last30.front().first + 30 <= d) {
                last30.pop(); 
            }

            last7.push({d, cost + cost[1]}); 
            last30.push({d, cost + cost[2]}); 
            cost = min({cost + cost[0], last7.front().second, last30.front().second}); 
        }      
        return cost; 
    }
};