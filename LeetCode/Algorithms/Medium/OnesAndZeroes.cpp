// Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
        int numZeros, numOnes;

        for (auto &s : strs)
        {
            numOnes = numZeros = 0;
            for (auto &c : s)
            {
                if (c == '1')
                    numOnes++;
                else if (c == '0')
                    numZeros++;
            }

            // zero m - count[0]  ------------ 0 
            // one  n - count[1]  ------------ 0
            for (int i = m; i >= numZeros; i--)
            {
                for (int j = n; j >= numOnes; j--)
                {
                    // 1st case we are not considering the string and in the 2nd case we're considering it 
                    memo[i][j] = max(memo[i][j], memo[i - numZeros][j - numOnes] + 1);
                }
            }
        }
        return memo[m][n];
    }
};

// Time Complexity - O(N**2) => O(len * M * N)
// Space Complexity - O(N**2) => O(N * M)


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        return helper(strs, m, n, 0); 
    }

    int helper(vector<string>& strs, int zero, int one, int index) {
        if(index == strs.size() || zero + one == 0) {
            return 0; 
        }

        // add 
        vector<int> count(2, 0); 

        for(auto &c: strs[index]) {
            count[c-'0']++; 
        }

        int consider = 0; 
        if(zero >= count[0] && one >= count[1]) {
            consider = 1 + helper(strs, zero - count[0], one - count[1], index+1);  
        }
        // skip 
        int skip = helper(strs, zero, one, index+1);

        return max(skip, consider);  
    }
};


class Solution {
public:
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(strs.size(), 0))); 
    return helper(strs, m, n, 0, dp); 
}

int helper(vector<string>& strs, int zero, int one, int index, vector<vector<vector<int>>> &dp) {
    if(index == strs.size() || zero + one == 0) {
        return 0; 
    }
    
    if(dp[zero][one][index] > 0) {
        return dp[zero][one][index];
    }

    // add 
    vector<int> count(2, 0); 

    for(auto &c: strs[index]) {
        count[c-'0']++; 
    }

    int consider = 0; 
    if(zero >= count[0] && one >= count[1]) {
        consider = 1 + helper(strs, zero - count[0], one - count[1], index+1, dp);  
    }
    // skip 
    int skip = helper(strs, zero, one, index+1, dp);

    dp[zero][one][index] = max(skip, consider); 
    return dp[zero][one][index];
    }
};