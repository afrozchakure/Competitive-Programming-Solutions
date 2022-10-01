class Solution {
public:
    // O(M * N)
    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        vector<vector<int>> dp(amount + 1, vector<int> (n + 1)); 
        
        for(int i=0; i<=coins.size(); i++) {
            dp[0][i] = 1; 
        }

        for(int a=1; a<=amount; a++) {
            for(int i=n-1; i>=0; i--) {
                dp[a][i] = dp[a][i+1];  // We skip the coin at position i 
                if(a - coins[i] >= 0) {  // it means we skip the point 
                    // adding the row elements 
                    dp[a][i] += dp[a - coins[i]][i];   
                }
            }
        }
        return dp[amount][0]; 
    }
};

// Brute Force - O(C ^ amount) 

// Memoization 
// dfs(i, a)  ... if a > 5 stop  -> m X n 

// O(m . n) => O(n) (DP solution)


// Total no. of ways ->  Try out all ways 
                        //   |
                        // Recursion


// f() 
//  base case  -> return 1 or 0 
// f() 
// f() 
//  return ( _ + _)

// Recurrence  
// 1. Expres in terms of index and target (index, target) 
// 2. Explore all possibilities  (1. Take it 2. Not take it)
// 3. Sum all possiblities and return 


// F() 
// if(index == 0)
//     return (T % a[0] == 0); 
// not take it = f(index, T)
    // Take = 0
// if(arr[index] <= T) take = f(index-1, T - nums[i])

// return notTake + take;

// Recusion -> Time Complexity - O(exponential) 
// SC ->  O(N)


// Recursion -> Memoization