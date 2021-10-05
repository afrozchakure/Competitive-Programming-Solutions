package KthLargestElementInAnArray;

/* 
Question Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
Question 215: Kth Largest Element in an Array [MEDIUM]

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Constraints:

1 <= k <= nums.length <= 104
-104 <= nums[i] <= 104
*/

import java.util.PriorityQueue;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for(int i:nums)
        {
            minHeap.add(i);
            if(minHeap.size()>k)
                minHeap.poll();
        }
        return minHeap.peek();
    }
}