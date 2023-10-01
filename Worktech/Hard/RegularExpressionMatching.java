class Solution {
	boolean isMatch (String s, String p) {
	   boolean dp[][] = new boolean[s.length() + 1][p.length() + 1];
        for(int i = 0; i <= s.length(); i++){
            for(int j = 0; j <= p.length(); j++){
                if(j == 0 && j == i) {
                    dp[i][j] = true;
				}
                else if(j == 0) {
                    dp[i][j] = false;
				}
                else if(i == 0 && p.charAt(j - 1) != '*') {
                    dp[i][j] = false;
				}
                else if(i == 0) {
                     dp[i][j] = dp[i][j - 2];
				}
                else {
                    if(p.charAt(j - 1) == '.' || s.charAt(i - 1) == p.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    if(p.charAt(j - 1) == '*'){
                        dp[i][j] = dp[i][j - 2];
						boolean match = ((p.charAt(j - 2) == '.' ||  p.charAt(j - 2) == s.charAt(i - 1)) && dp[i - 1][j]);
						dp[i][j] = dp[i][j] || match;
                    }
                }
            }
        }
        return dp[s.length()][p.length()];
	}
}

