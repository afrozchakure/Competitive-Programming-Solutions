# Method - 1
from collections import Counter
class Solution:
    def firstUniqChar(self, s: str) -> int:
        charCount = Counter(s)
        for i in s:
            if charCount[i] == 1:
                return s.index(i)
        return -1

# Time Complexity - O(n)
# Space Complexity - O(1)

# Method - 2
class Solution:
    def firstUniqChar(self, s: str) -> int:
        for i in s:
            if s.count(i) == 1:
                return s.index(i)
        return -1

# Time Complexity - O(n**2)
# Space Complexity - O(n)