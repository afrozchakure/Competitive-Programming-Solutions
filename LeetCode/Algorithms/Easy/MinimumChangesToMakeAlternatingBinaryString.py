class Solution:
    def minOperations(self, s: str) -> int:
        ans = 0
        for i in range(len(s)):
            if(i % 2 == 0 and s[i] == '1'):
                ans += 1
            if(i % 2 == 1 and s[i] == '0'):
                ans += 1
        return min(ans, len(s) - ans)
        
# Time Complexity - O(N)
# Space Complexity - O(1)
