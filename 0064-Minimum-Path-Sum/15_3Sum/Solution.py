class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        if nums == None or len(nums)<3:
            return None
        
        
        ans = []
        n = len(nums)
        nums.sort()
        l = 0
        r = n -1
        for i in range(n):
            sm = 0-nums[i]        
            while l<r:
                if nums[l]+nums[r] == sm:
                    ans.apend([nums[i],nums[l],nums[r]])
                elif nums[l]+nums[r]>sm:
                    while r-1>-1 and nums[r-1]==nums[r]:
                        r -= 1
                else:
                    while l+1<n and nums[l]==nums[l+1]:
                        l += 1
        
        return ans

s = Solution()
print(s.threeSum([-1,0,1,2,-1,-4]))