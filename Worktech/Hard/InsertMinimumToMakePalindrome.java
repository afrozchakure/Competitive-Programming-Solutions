class Solution {
	int minCharactersToBeInserted (String s) {
	 StringBuilder rev = new StringBuilder();
		rev.append(s);
		rev.reverse();
		s += '#';
		s += rev;
		int n = s.length(), palindromeLength = 0;
		int[] lps = new int[n];
		lps[0] = 0;
		int i = 1;
		while(i < n) {
			if (s.charAt(i) == s.charAt(palindromeLength)) {
				palindromeLength++;
				lps[i++] = palindromeLength;
			} else {
				if (palindromeLength == 0)
					lps[i++] = 0;
				else
					palindromeLength = lps[palindromeLength - 1];
			}
		}
		int ans = n / 2 - lps[n - 1];
		return ans;
	}
	
}
