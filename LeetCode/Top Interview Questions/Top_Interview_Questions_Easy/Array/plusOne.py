#############Method 1#########################
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        a = [str(i) for i in digits]
        str_a = int("".join(a))
        str_a = str(str_a + 1)
        str_a = list(str_a)
        str_a = [int(i) for i in str_a]
        return str_a
        
# Time Complexity - O(n)
# Space Complexity - O(3n)
############Method2#########################        
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        temp = ""
        for i in digits:
            temp += str(i)
        sum = int(temp)
        sum = sum+1
        temp = str(sum)
        result = []
        for j in temp:
            result.append(j)
        return result
        
# Time Complexity - O(n)
# Space Complexity - O(n)
