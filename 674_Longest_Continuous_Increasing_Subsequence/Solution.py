class Solution:
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return 1
        mx  = 1
        i = 0
        for j in range(1,n):
            if nums[j-1] >= nums[j]:
                mx = max(mx,j-i)
                i = j
        mx = max(mx,j-i) 
        return mx


s = Solution()
print(s.findLengthOfLCIS([1,3,5,7]))