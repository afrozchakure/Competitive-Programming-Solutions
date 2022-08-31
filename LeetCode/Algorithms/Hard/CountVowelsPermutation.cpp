// Recursive Solution (Brute-Force)
class Solution {
    const int MOD = 1e9 + 7; 
    const unordered_map<char, vector<char>> mappings { {'s', {'a', 'e', 'i', 'o', 'u'}, 
                                                       {'a', {'e'}}, 
                                                       {'e', {'a', 'i'}}, 
                                                       {'i', {'a', 'e', 'o', 'u'}}, 
                                                       {'o', {'i', 'u'}}, 
                                                       {'u', {'a'}}};

    public int countVowelPermutation(int n) {
        return solve(n, 's');   // start with s
    }

    int solve(int rem, char prev) {
        if(rem = 0) return 1; 
        int ans = 0; 
        for(auto c: mappings.at(prev)) {
            ans = (ans + solve(rem-1, c)) % MOD; 
        }

        return ans;
    }
};

// Time Complexity - O(5^N)
// Space Complexity - O(N)

// Method - 2 (Dynamic Programming - Top-Down Recursive)
class Solution {
    const int MOD = 1e9 + 7; 
    const unordered_map<char, vector<char>> mappings { {'s', {'a', 'e', 'i', 'o', 'u'}, 
                                                       {'a', {'e'}}, 
                                                       {'e', {'a', 'i'}}, 
                                                       {'i', {'a', 'e', 'o', 'u'}}, 
                                                       {'o', {'i', 'u'}}, 
                                                       {'u', {'a'}}};
    unordered_map<char, vector<char>> dp; 

    public int countVowelPermutation(int n) {
        dp['s'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int>(n+1);
        return solve(n, 's');   // start with s
    }

    int solve(int rem, char prev) {
        if(rem = 0) return 1;    // no need to pick further, We have formed 1 string of length = n.
        if(dp[prev][rem]) return dp[prev][rem];  // if result already calculated for current state, directory return it
        for(auto c: mappings.at(prev)) {
            dp[prev][rem] = (dp[prev][rem] + solve(rem-1, c)) % MOD; 
        }

        return dp[prev][rem];
    }
};

// Dynamic Programming - Bottom-Up Iterative 

// 0 (a)  => 1 
// 1 (e)  => 0, 2  
// 2 (i)  => 0, 1, 3, 4
// 3 (o)  => 2, 4 
// 4 (u)  => 0 

class Solution {
    public int countVowelPermutation(int n) {
            const int MOD = 1e9 + 7;
            long dp[5][n+1], ans = 0;
            dp[0][1] = dp[1][1] = dp[2][1] = dp[3][1] = dp[4][1] = 1; 
            for(int i=2; i<=n; i++) {
                dp[0][i] = dp[1][i-1];
                dp[1][i] = (dp[0][i-1] + dp[2][i-1]) % MOD;
                dp[2][i] = (dp[0][i-1] + dp[1][i-1] + dp[3][i-1] + dp[4][i-1]) % MOD; 
                dp[3][i] = (dp[2][i-1] + dp[4][i-1]) % MOD; 
                dp[4][i] = dp[0][i-1];
            }
        }

        for(int i=0; i<5; i++) {
            ans = (ans + dp[i][n]) % MOD; 
        }

        return ans;
    }
};

// Time Complexity - O(N) 
// Space Complexity - O(N)