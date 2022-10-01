class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1)); 

        // column value setting 3, 2, 1
        for(int j=0; j<word1.size(); j++) {
            dp[j][word2.size()] = word1.size() - j; 
        }

        // row value as 1, 2, 3
        for(int j=0; j<word2.size(); j++) {
            dp[word1.size()][j] = word2.size() - j; 
        }

        for(int i=word1.size() - 1; i>=0; i--) {
            for(int j=word2.size()-1; j>=0; j--) {
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+ 1]; 
                } else {
                    dp[i][j] = 1 + min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]));
                }
            }
        }
        return dp[0][0]; 
    }
};
         // i 
// word1 = abd
        //  j
// word2 = acd 

// if  w1[i] == w2[j]: 
//     (i + 1, j + 1)  -> 0 operations 
// else:  // we will be taking minimum of below value
//     insert: (i, j + 1) -> 1 operatino 
//     delete: (i + 1, j) -> 1 operation 
//     replace: (i + 1, j + 1) -> 1 operation


// Do bottom up dynamic programming

words2 - cols 
words1 - rows 

for(int i=0)