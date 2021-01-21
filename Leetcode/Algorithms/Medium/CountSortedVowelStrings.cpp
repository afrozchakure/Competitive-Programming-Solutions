class Solution
{
public:
    int countVowelStrings(int n)
    {
        return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
    }
};

// Time Complexity - O(1)
// Space Complexity - O(1)

class Solution
{
public:
    int countVowelStrings(int n)
    {

        vector<int> dp = {0, 1, 1, 1, 1, 1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                dp[j] += dp[j - 1];
            }
        }
        return dp[5];
    }
};

// Time Complexity - O(n*k)
// Space Complexity - O(k), Constant space
// where k = 5