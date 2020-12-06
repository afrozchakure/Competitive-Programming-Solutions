class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()
        count = 0
        start = 0
        end = len(nums) - 1
        while(start < end):
            val = nums[start] + nums[end]
            if(val == k):
                count += 1
                nums.pop(start)
                end -= 1
                nums.pop(end)
                end -= 1
            elif(val > k):
                end-=1
            elif(val < k):
                start+=1
            
        return count