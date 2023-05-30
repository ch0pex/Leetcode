from typing import List


"""Brute force: 
    - Runtime 114ms
    - Memory 16.6MB
 """

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]):
        merged: List[int] = nums1 + nums2 
        merged.sort()
        if len(merged) % 2 == 0: 
            return (merged[len(merged) // 2] + merged[(len(merged) // 2) - 1]) / 2 
        else:
            return merged[len(merged) // 2]