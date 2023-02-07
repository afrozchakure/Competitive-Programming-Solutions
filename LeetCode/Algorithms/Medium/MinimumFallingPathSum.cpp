class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
    }
};

// When uniformity is not there, you cannot apply Greedy

// Try out all the paths 
// 1. Recursion 

// 1. Express everything in terms of i, j and base case 
// 2. Explore all the paths 
// 3. Max among all the paths 

// f(i, j) -> max path sum to reach (i, j) from any cell in the first row

// Base Case -> Destination 
//     |
//     Out of bound Cases 

    // 0th 
    // ^
    // |
    // n-1

f(i, j) {
    if(j<0 || j>= m) return -1e9; 
    if(i == 0) return a[0][j]; 

    int straight = a[i][j] + f(i-1, j); 
    int left = a[i][j] + f(i-1, j-1); 
    int right = a[i][j] + f(i-1, j+1);

    return max(straight, max(left, right)); 
}

// TC -> 3 ^ n ~~ Exponential in nature  -> Gives TLE
// SC -> O(N) 

// Recursion -> Overlapping subproblems -> Memoization

// dp[i][j] is required for memoization

f(i, j) {
    if(j<0 || j>= m) return -1e9; 
    if(i == 0) return a[0][j]; 

    if(dp[i][j] != -1) return dp[i][j]; 
    int straight = a[i][j] + f(i-1, j); 
    int left = a[i][j] + f(i-1, j-1); 
    int right = a[i][j] + f(i-1, j+1);

    return dp[i][j] = max(straight, max(left, right)); 
}

// TC -> O(N * M) 
// SC -> O(N * M) + O(N) -> O(N *M) for the dp and O(N) for recursion stack space

// The time complexity will be more than N * M, so we use 
// tabulation format to optimize it

// Tabulation -> Bottom-up 

// Steps for tabulation: 
// 1. Write the base case 
// 2. Observe (i, j) & convert to loops  

int dp[n][m]; 

// base case 
for(int j=0; j<m-1; j++) 
    dp[0][j] = a[0][j]; 
for(i = 1 to n-1) {
    for(j = 0 to m-1) {
        straight = a[i][j] + dp[i-1][j]; 
        if(j-1 >= 0)
            left = a[i][j] + dp[i-1][j-1]; 
        if(j+1 < m)
            right = a[i][j] + dp[i-1][j+1]; 

        dp[i][j] = max(straight, left, right); 
    }
}
n-1 to 0 
// TC -> O(N * M) + O(M)

// Whenever you see i-1, there is a possiblity of space optimization 