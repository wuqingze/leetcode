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
    
    def searchMid(self, nums):
        n = len(nums)
        if n == 1:
            return 0
        if n == 2:
            if nums[0] > nums[1]:
                return 1
            else:
                return 0
        low = 0
        hight = n - 1
        while low < hight:
            mid = (hight+low)//2
            if mid == low:
                if nums[low] > nums[hight]:
                    return hight
                else:
                    return low
            if nums[low] == nums[hight]:
                if nums[mid] > nums[hight]:
                    low = mid
                if nums[mid] == nums[hight]:
                    low += 1
                if nums[mid] < nums[hight]:
                    hight = mid
            if nums[low] > nums[hight]:
                if nums[mid] > nums[hight]:
                    low = mid
                if nums[mid] == nums[hight]:
                    hight = mid
                if nums[mid] < nums[hight]:
                    hight = mid
            if nums[low] < nums[hight]:
                break
        return low
    def search(self, nums, target):
        if None == nums or [] == nums:
            return False
        n = len(nums)
        # pre = nums[0] -1 
        # i = 0
        # while i< n and nums[i] >= pre:
        #     pre = nums[i]
        #     i += 1
        i = self.searchMid(nums)
        if self.binarySearch(0, i-1, nums, target):
            return True
        if self.binarySearch(i, n-1, nums, target):
            return True
        return False