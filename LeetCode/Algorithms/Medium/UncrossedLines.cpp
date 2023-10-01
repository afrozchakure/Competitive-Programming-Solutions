class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), dp[m + 1][n + 1]; 

        memset(dp, 0, sizeof(dp)); 

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                dp[i][j] = A[i-1] == B[j-1] ? dp[i-1][j-1] + 1 : max(dp[i][j-1], dp[i-1][j]); 
            }
        }      
        return dp[m][n]; 
    }
};