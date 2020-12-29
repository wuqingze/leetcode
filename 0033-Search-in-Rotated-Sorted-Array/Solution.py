class Solution:
#     def search(self, nums: List[int], target: int) -> int:
#         for i in range(len(nums)):
#             if nums[i] == target:
#                 return i
            
#         return -1
    def search(self, nums, target: int):
        
        n = len(nums)
        if n < 3:
            if nums[0] != target and target[n-1] != target:
                return -1
            else:
                if target[n-1] == target:
                    return n-1
                else:
                    return 0
                
        l = 0
        h = n-1
        while l< h:
            mid = (l+h)//2
            if nums[mid] < nums[0] and nums[mid]<nums[-1]:
                h = mid -1
            elif nums[mid] > nums[0] and nums[mid] > nums[-1]:
                l = mid + 1
            else:
                break
        e = -1
        s = -1
        if l - 1 >=0 and l+1 <n:
            if nums[l] > nums[l-1] and nums[l] > nums[l+1]:
                e = l
                s = l+1
            else:
                e = l -1
                s = l
        elif l-1>= 0:
            e = l - 1
            s = l
        else:
            e = l
            s = l+1
            
        l = 0
        h = e
        while(l<=h):
            mid = (l+h)//2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                l = mid + 1
            else:
                h = mid - 1
        
        l = s
        h = n-1
        while(l<=h):
            mid = (l+h)//2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                l = mid + 1
            else:
                h = mid - 1
        
        
        
        return -1
                

s = Solution()
# print(s.search([4,5,6,7,0,1,2],0))
# print(s.search([1,3,5],0))
print(s.search([8,9,2,3,4],9))