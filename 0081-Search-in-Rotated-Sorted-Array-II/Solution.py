class Solution:
    def binarySearch(self, i, j, nums, target):
        low = i
        hight = j
        while low<=hight:
            mid = (low+hight)//2
            if nums[mid] == target:
                return True
            if nums[mid] < target:
                low = mid + 1
            if nums[mid] > target:
                hight = mid -1
        return False
    
    def search(self, nums: List[int], target: int) -> bool:
        if None == nums or [] == nums:
            return False
        n = len(nums)
        pre = nums[0] -1 
        i = 0
        while i< n and nums[i] >= pre:
            pre = nums[i]
            i += 1
        if self.binarySearch(0, i-1, nums, target):
            return True
        if self.binarySearch(i, n-1, nums, target):
            return True
        return False
        