class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(); 
        int c = grid[0].size(); 
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        return func(0, 0, c-1, r, c, grid, dp);
    }

    int func(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if(i < 0 || j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) {
            return -1e5; 
        }

        if(dp[i][j1][j2] != -1) {
            return dp[i][j1][j2]; 
        }

        if(i == r -1 ) {
            if(j1 == j2) {
                return grid[i][j1]; 
            } else {
                return grid[i][j1] + grid[i][j2]; 
            }
        }

        // explore all paths of alice and bob simultaneously 
        int maxi = -1e5; 
        for(int dj1 = -1; dj1 <= +1; dj1++) {
            for(int dj2 = -1; dj2 <= +1; dj2++) {
                int value = 0; 
                if(j1 == j2) {
                    value = grid[i][j1];
                } else {
                    value = grid[i][j1] + grid[i][j2]; 
                }

                value += func(i+1, j1 + dj1, j2 + dj2, r, c, grid, dp); 
                maxi = max(maxi, value); 
            }
        }
        return dp[i][j1][j2] = maxi; 
    }
};


// Rules 
// 1. Express everything in terms (i1, j1) && (i2, j2); 
// 2. Explore all the paths (i+1, j-1), (i + 1, j), (i + 1, j + 1)
// 3. Give maximum sum 

// Fixed starting point     variable ending point
// (0, 0)    (0, m-1)        (set any column in the last row)

// (all paths by Alice) + (all paths by Bob)
// (recursion)              (recursion)

// f(i1, j1, i2, j2)
// f(0, 0, 0, m-1);
//   alice   bob 

// base case 
// 1. Destination base case 
// 2. Out of bounds case 

// f(i, j1, j2)  // i1 == i2;
// {
//     if(i1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
//         return -1e8;  // not INT_MIN (since it can go out of bounds)
//     }

//     if(dp[i][j1][j2] != -1) {
//         return dp[i][j1][j2]; 
//     }

//     if(i == n-1) {
//         if(j1 == j2) {
//             return a[i][j1]; 
//         } else {
//             return a[i][j1] + a[i][j2]; 
//         }
//     }

// }

// 3 * 3 = 9 combos of paths 
// for each movement of alice, there are 3 moves for Bob 

// dj[] = {-1, 0, +1};
// fun(del1() -> -1 -> +1) 
// fun(del2() -> -1 -> +1)

// Explore all paths Alice & Bob can go together 

// func(){
// for(dj1 -> -1 -> +1) {
//     for(dj2 -> -1 -> +1) {
//         if(j1 == j2) {
//             maxi = max(maxi, a[i][j1] + f(i + 1, j1 + dj1, j2 + dj2)); 
//         } else {
//             maxi = max(maxi, a[i][j1] + a[i][j2] + f(i + 1, j1 + dj1, j2 + dj2)); 
//         }
//     }
// }
// dp[i][j1][j2] = maxi; 
// return maxi; 
// }

// Recursion - TC -> (3^n X 3^n), exponential 
//             SC -> O(N), auxillary stack space 

// Optimize - find overlapping sub problems 
// Memoization 

// i - N 
// j1 - M 
// j2 - M 

// dp[i][j1][j2] = maxi; 

// Memoization - TC - O(N * M * M) * 9 
// Space Complexity - O(N * M * M) * O(N), O(N) is the Auxillary stack space 


