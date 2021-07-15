class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        
        vector<vector<int>> dp(len1 + 1, vector<int> (len2 + 1, 0));
        
        for(int i=len1-1; i>=0 ; i--)
        {
            for(int j=len2-1; j>= 0; j--)
            {
                if(text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else 
                {
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
            
    }
};

//   a c e -
// a 3 2 1 0
// b 2 2 1 0
// c 1 2 1 0
// d 1 1 1 0
// e 1 1 1 0
// - 0 0 0 0

// If the characters are equal simply add 1 to diagonal value and if the characters are different take the maximum from the bottom and right values in the dp matrix

// Time Complexity - O(N * M), N and M is the length of text1 and text2 respectively
// Space Complexity - O(N * M)
