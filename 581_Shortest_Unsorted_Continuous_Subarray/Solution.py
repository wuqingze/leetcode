class Solution:
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        t = sorted(nums)
        i = 0
        n = len(nums)
        for i in range(n):
            if nums[i] != t[i]:
                break
            
        
        j = n-1
        while j>i and nums[j] == t[j]:
            j -= 1
        return n - i -(n-j-1)

s = Solution()
print(s.findUnsortedSubarray([1,2,3,4]))