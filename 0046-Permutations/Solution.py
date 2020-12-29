class Solution:
    def xx(self,i,n,nums,ans):
        if i == n-1:
            ans.append(list(nums))
        else:
            for j in range(i,n):
                t = nums[j]
                nums[j] = nums[i]
                nums[i] = t
                self.xx(i+1,n,nums,ans)
                t = nums[j]
                nums[j] = nums[i]
                nums[i] = t
                
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        ans = []
        self.xx(0,n,nums,ans)
        return ans
s = Solution()
print(s.permute([1,2,3,4,5,6,7,8,9,0]))