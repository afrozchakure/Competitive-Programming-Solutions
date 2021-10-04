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

            for (int i = m; i >= numZeros; i--)
            {
                for (int j = n; j >= numOnes; j--)
                {
                    memo[i][j] = max(memo[i][j], memo[i - numZeros][j - numOnes] + 1);
                }
            }
        }
        return memo[m][n];
    }
};

// Time Complexity - O(N**2)
// Space Complexity - O(N**2)