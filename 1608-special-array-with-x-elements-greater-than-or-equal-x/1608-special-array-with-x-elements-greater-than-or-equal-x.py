class Solution:
    def specialArray(self, nums: List[int]) -> int:
        # Sort the array
        nums.sort()
        
        # Iterate through each possible x from 0 to len(nums)
        for x in range(1, len(nums) + 1):
            # Count the number of elements greater than or equal to x
            count = len(nums) - bisect.bisect_left(nums, x)
            
            # If count matches x, then x is the special number
            if count == x:
                return x
        
        # If no special number found, return -1
        return -1
