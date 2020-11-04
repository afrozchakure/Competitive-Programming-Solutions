class Solution:
    def maxPower(self, s: str) -> int:
        max_count = 1
        count = 1
        for i in range(len(s)-1):
            if(s[i] == s[i+1]):
                count += 1
            if(count > max_count):
                max_count = count
            if(s[i] != s[i+1]):
                count = 1
        return max_count

# Time Complexity - O(n)
# Space Complexity - O(1) -> Linear Space
