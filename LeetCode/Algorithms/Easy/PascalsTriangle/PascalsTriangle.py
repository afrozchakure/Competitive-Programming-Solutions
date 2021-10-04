class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result = [[1]]
        for i in range(1, numRows):
            temp1 = result[-1] + [0]
            temp2 = [0] + result[-1]
            result.append([temp1[i] + temp2[i] for i in range(len(temp1))])
        return result[:numRows]
            
        
# Time Complexity - O(n**2)\
# Space Complexity - O(n)
        
"""
explanation: Any row can be constructed using the offset sum of the previous row. Example:

    1 3 3 1 0 
 +  0 1 3 3 1
 =  1 4 6 4 1
 """
