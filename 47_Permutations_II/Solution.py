class Solution:
    def _per(self, nums, i, n, result):
        if i >= n:
            if nums not in result:
                result.append([ii for ii in nums])
            return

        for j in range(i,n):
            temp = nums[j]
            nums[j] = nums[i]
            nums[i] = temp
            self._per(nums,i+1,n,result)
            temp = nums[j]
            nums[j] = nums[i]
            nums[i] = temp

    def permuteUnique(self, nums):
        if None == nums or [] == nums:
            return nums

        n = len(nums)
        result = []
        self._per(nums,0,n,result)
        return result

s = Solution()
print(s.permuteUnique([1,1,2]))
print(s.permuteUnique([1]))
print(s.permuteUnique([1,1]))

