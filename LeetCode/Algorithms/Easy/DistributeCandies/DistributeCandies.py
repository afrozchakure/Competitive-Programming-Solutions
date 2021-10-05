class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        set_candy = set(candyType)
        len_set_candy = len(set_candy)
        
        candy_len = len(candyType)
        
        num_candies = candy_len / 2 
        
        if(len_set_candy < num_candies):
            return int(len_set_candy)
        else:
            return int(num_candies)
# Time Complexity - O(N), since iterating over a list is O(N) and adding each element to the hast set is O(1), so the total operation is O(N).
# Space Complexity - O(N), using set
