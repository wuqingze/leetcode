class Solution:
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
#         a = 0
#         for i in range(len(nums)):
#             a ^= nums[i]
            
#         return a
        n = len(nums)
        mid = n // 2
        i = 0
        j = n-1
        while mid !=0 and mid != (n-1) and (nums[mid]!=nums[mid-1] or nums[mid]!= nums[mid+1]):
            if nums[mid] == nums[mid-1] and (mid-i)%2==0:
                j = mid
            else:                
                i = mid
            mid = (j-i)//2+i
        ans = nums[mid]
        return nums[mid]

s = Solution()
print(s.singleNonDuplicate([1,1,2,2,4,4,5,5,9]))