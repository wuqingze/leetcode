class Solution:
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        for i in range(len(nums)):
            if nums[nums[i]-1] < 0:
                ans.append(abs(nums[i]))
            else:
                nums[nums[i]-1] = 0 - nums[nums[i]-1]
                
        return ans
                
s = Solution()
print(s.findDuplicates([2,2]))