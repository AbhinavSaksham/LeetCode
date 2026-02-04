from typing import List

class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        
        # Phase 1: Find end of first strictly increasing section (find p)
        p = 0
        while p < n - 2 and nums[p] < nums[p + 1]:
            p += 1
        
        # Must have some increasing section at the start
        if p == 0:
            return False
        
        # Phase 2: From p, find end of strictly decreasing section (find q)
        q = p
        while q < n - 1 and nums[q] > nums[q + 1]:
            q += 1
        
        # Must have some decreasing section AND room for final increasing
        if q == p or q == n - 1:
            return False
        
        # Phase 3: From q, verify strictly increasing to the end
        while q < n - 1 and nums[q] < nums[q + 1]:
            q += 1
        
        # Valid if we reach exactly the end of array
        return q == n - 1
