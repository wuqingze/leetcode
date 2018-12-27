class Solution:
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        
        if n == 1:
            return nums[0]
        
        if nums[0]<nums[-1]:
            return nums[0]
        
        
        l = 0
        r = n-1
        mid = 0
        while l<=r:
            mid = l+(r-l)//2
            if mid == 0:
                if nums[mid] > nums[mid+1]:
                    return mid+1
                else:
                    l = mid + 1
            elif mid == n-1:
                if nums[mid]<nums[mid-1]:
                    return nums[mid]
                else:
                    r = mid - 1
            elif nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]:
                return nums[mid+1]
            elif nums[mid] > nums[0]:
                l = mid + 1
            elif nums[mid] < nums[0]:
                r = mid -1
        return nums[mid]
s = Solution()
# s.findMin([3,4,5,1,2])
s.findMin([9,0,2,7,8])