class Solution:
    def subsetsWithDup(self, nums):
        if None == nums or [] == nums:
            return nums

        n = len(nums)
        nums = sorted(nums)
        i = 0
        result = [[]]
        while i < n:
            c = 1
            while i< n and i+1<n and nums[i] == nums[i+1]:
                c += 1
                i += 1
            rl = len(result)
            for w in range(rl):
                for j in range(1,c+1):
                    tt = list(result[w])
                    for k in range(j):
                        tt.append(nums[i])
                    result.append(tt)
            
            i += 1

        return result
s = Solution()
print(s.subsetsWithDup([1,2,2]))