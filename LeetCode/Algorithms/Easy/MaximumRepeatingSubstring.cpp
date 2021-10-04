class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        
        result = sequence.count(word)
        
        check_word = word*result
        while(check_word not in sequence):
            result-=1
            check_word = word * result
        
        return result
        
