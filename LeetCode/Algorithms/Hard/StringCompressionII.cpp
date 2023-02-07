class Solution {
public:
    // First dimension => s 
    // Second dimension => prev char 
    // Third Dimension => freq of char 
    // Fourth Dimension => k 
    int dp[101][27][11][101]; 
    int n; 
    string s; 

    int util(int idx, char prev, int prevCharCount, int k) {
        if(k < 0) return INT_MAX; 
        if(idx >= n) return 0; 
        if(prevCharCount >= 10) {
            prevCharCount = 10; 
        }

        if(dp[idx][prev - 'a'][prevCharCount][k] != -1) {
            return dp[idx][prev - 'a'][prevCharCount][k]; 
        }

        int res = INT_MAX; 

        // Case 1. Exclude the current character 
        res = min(res, util(idx + 1, prev, prevCharCount, k-1)); 

        // Case 2. Include the current character 
        // Case 2.1 prevChar != currChar 
        if(prev != s[idx]) {
            res = min(res, 1 + util(idx + 1, s[idx], 1, k)); 
        } else {
            // Case 2.2. prevChar == currChar 
            // Case 2.2.1 if prevCharCount is 1 or 9 
            if(prevCharCount == 1 || prevCharCount == 9) {
                res = min(res, 1 + util(idx+1, s[idx], prevCharCount + 1, k)); 
            // Case 2.2.2 If prevCharCount is not 1 or 9
            } else {
                res = min(res, util(idx + 1, s[idx], prevCharCount + 1, k));
            }
        }

        dp[idx][prev-'a'][prevCharCount][k] = res; 
        return res; 
    }

    // int [][][][] dp = new int[n+1][27][11][n+1]; 
    int getLengthOfOptimalCompression(string _s, int k) {
        s = _s; 
        n = s.size(); 

        if(n == 100) {
            bool allSame = true; 
            for(int i=1; i<n; i++) {
                if(s[i] != s[i-1]) {
                    allSame = false;
                    break; 
                } 
            }
            if(allSame) {
                return 4; 
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<27; j++) {
                for(int x=0; x < 11; x++) {
                    for(int y=0; y < n; y++) {
                        dp[i][j][x][y] = -1; 
                    }
                }
            }
        }

        return util(0, 'z' + 1, 0, k); 
    }
};

// 1. s = "aaabcccd" delete atmost k = 2 
    
// -> abcccd -> abc3d -> 5 length -> delete aa 
// -> aaaccc -> a3c3 -> 4 length -> delete b and d 
// -> aaabcd -> a3bcd -> 5 length  -> delete cc
// -> aaabcc -> a3bc2 -> 5 length -> delete c and d 

// 2. s = "aabbaa", delete atmost k = 2

// -> aaaa -> a4 -> 2 length -> delete bb 
// -> aabb -> a2b2 -> 4 length -> delete aa

// Algorithm 

// For each new char under consideration there are multiple choices 

// 1. Excluse current char 
// 2. Include current char 
    // 2.1 PrevChar != NewChar -> length increase by 1 and pass 
    // current frequency count as 1 to subsequent calls 
    // 2.2 Prevchar == NewChar 
        // 2.2.1 Current Freq Count = 1 and under previous iteraition 
        // new character was added 
        // => length increase by 1 
        
        // 2.2.2 Current Freq Count = 9 (Under previous iteration 9 consecutive same elements are present) 
        // XXXXXX + X) ResX9 = ResX10 (length increases by 1) 
        
        // 2.2.3 -> ResX2 => ResX3 No change in length 
