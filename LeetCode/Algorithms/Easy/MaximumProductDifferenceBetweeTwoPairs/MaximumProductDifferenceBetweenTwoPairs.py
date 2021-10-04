class Solution(object):
    def maxProductDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        n = len(nums)
        a, b, c, d = nums[n-1], nums[n-2], nums[0], nums[1]
        
        return (a*b) - (c*d)
        
# Time Complexity - O(nlogn)
# Space Complexity - O(1)

