class Solution:
    def defangIPaddr(self, address: str) -> str:
        a = ""
        for i in range(len(address)):
            if address[i] == '.':
                a += '[.]'
            elif address[i] != '.':
                a += address[i]
        return a

# Time Complexity - O(n)
# Space Complexity - O(n)