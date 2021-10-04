class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n = len(s)
        half_n = int(n/2)
        # print(half_n)
        first = s[:half_n]
        second = s[half_n:]
        
        count_first = 0
        count_second = 0
        s = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        for i in first:
            if(i in s):
                count_first += 1
        for i in second:
            if(i in s):
                count_second += 1
                
        if(count_first == count_second):
            return True
        return False
        