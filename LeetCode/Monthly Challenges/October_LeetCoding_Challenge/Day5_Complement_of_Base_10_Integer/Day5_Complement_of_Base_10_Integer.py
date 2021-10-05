class Solution:
    def bitwiseComplement(self, N: int) -> int:
        bin_N = bin(N)[2:]
        result = ""
        for i in str(bin_N):
            if i == "0":
                result += "1"
            if i == "1" :
                result += "0"
        return int(result, 2)
        
# Time Complexity - O(n)
# Space Complexity - O(1)

# Time Complexity of bin() function in python is O(logn)
