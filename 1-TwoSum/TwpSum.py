from typing import List

""" 
Solution: 
    - Runtime 85ms 
    - Memory 17MB
    - Complexity: O(n) 
"""
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen: dict[int,int]= {}
        for i in range(len(nums)):
            print(nums[i])  
            check: int = target - nums[i] 
            if seen.get(check) is not None: 
                return [seen[check], i]
            seen[nums[i]] = i 


