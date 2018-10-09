class Solution:
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sm = sum(nums)
        print(sm)
        t = 0
        for i in range(len(nums)):
            if t == (sm - nums[i])/2:
                return i
            else:
                t += nums[i]
        return -1

s = Solution()
print(s.pivotIndex([-1,-1,-1,-1,-1,-1]))