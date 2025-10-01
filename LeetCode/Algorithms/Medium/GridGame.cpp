class Solution {
public:
    #define ll long long 
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(n < 2) return 0; 

        ll minSum = LONG_MAX;  // remember this is LONG_MAX
        ll bottomSum = 0;
        ll topSum = accumulate(grid[0].begin(), grid[0].end(), 0LL); 

        for(int i=0; i<n; i++) {
            topSum -= grid[0][i];
            minSum = min(minSum, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }
        return minSum; 
    }
};

// Time Complexity - O(N)
// Space Complmexity - O(1), since we're using variables

/*

Required time complexity - < N^2

Note: If a robo comes down then it can't go up. 

Robo 1 choses a path which minimizes the sum for robo-2 
Return the sum for Robo - 2 (it also tries to maximize the sum)

Optimal strategy -> 


Robo-2 picks = max(top sum, bottom sum)

Robo-1 will choose a partition point which 
minimizes the value for Robo-2 pick 

for(pp=0; pp<n; ++pp) {
    topSum += grid[0][pp];
    minSum = min(minSum, max(topSum, bottomSum));
    bottomSum -= grid[1][pp];
}


Available Option

TopSum = 10
minSum = INT_MAX
BottomSum = 0 

Time Complexity - O(N)
Space Complmexity - O(1), since we're using variables
*/