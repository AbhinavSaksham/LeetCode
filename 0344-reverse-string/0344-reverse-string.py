class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        left = 0
        right = len(s) - 1
        
        while left < right:
            # Swap characters at left and right indices
            s[left], s[right] = s[right], s[left]
            
            # Move left pointer to the right and right pointer to the left
            left += 1
            right -= 1
