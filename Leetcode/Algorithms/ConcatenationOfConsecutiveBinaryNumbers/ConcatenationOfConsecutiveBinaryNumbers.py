class Solution:
    def concatenatedBinary(self, n: int) -> int:
        result = ""
        for i in range(1, n+1):
            result = result + bin(i)[2:]
        return int(result, 2) % (10**9 + 7)
