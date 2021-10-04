class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) < len(nums2):
            nums1, nums2 = nums2, nums1
        seen = {}
        for i in nums1:
            if i not in seen:
                seen[i] = 1
            else:
                seen[i] += 1
        nums1 = []
        for j in nums2:
            if j in seen and seen[j] > 0:
                nums1.append(j)
                seen[j] -= 1
          
        return nums1
        
# Time Complexity - O(m + n)
# Space Complexity - O(max(m, n))
