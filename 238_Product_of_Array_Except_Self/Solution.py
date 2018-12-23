class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        ans = [1]*n
        for i in range(1,n):
            ans[i] = nums[i-1]*ans[i-1]
        t = 1
        for i in range(n-1,-1,-1):
            ans[i] *= t
            t *=nums[i]
            
        return ans

s = Solution()
print(s.productExceptSelf([1,2,3,4]))