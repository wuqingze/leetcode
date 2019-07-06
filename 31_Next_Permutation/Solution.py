class Solution:
    def nextPermutation(self, nums):#: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return
        
        n = len(nums)
        if n<=1:
            return
        
        i = n-1
        flag = 0
        while i>=0:
            if i>0 and nums[i]>nums[i-1]:
                j = n-1
                while j>=i:
                    if nums[j] > nums[i-1]:
                        t = nums[i-1]
                        nums[i-1] = nums[j]
                        nums[j] = t
                        break
                    j -= 1
                flag = 1
                
            if i == 0 or flag == 1:
                j = i
                k = n-1
                while j<k:
                    t = nums[k]
                    nums[k] = nums[j]
                    nums[j] = t
                    j += 1
                    k -= 1
                break
            else:
                i -= 1

s = Solution()
nums = [1,3,2]
s.nextPermutation(nums)
print(nums)