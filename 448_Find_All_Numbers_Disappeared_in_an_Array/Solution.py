class Solution:
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        n = len(nums)
        for i in range(n):
            nums[nums[i]-1] = -1
        for i in range(n):
            if nums[i] != -1:
                ans.append(i+1)
        return ans
nums = [4,3,2,7,8,2,3,1]
S = Solution()
print(S.findDisappearedNumbers(nums))