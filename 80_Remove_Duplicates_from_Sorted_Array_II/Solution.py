class Solution:
    def removeDuplicates(self, nums):
        if nums == None:
            return 0
        if len(nums) == 0:
            return 0
        n = len(nums)
        if n <=2:
            return n
        count = 0
        pre = nums[0] - 1
        result = 0
        while result < len(nums):
            if nums[result] == pre:
                count += 1
            else:
                count = 1
            if count == 3:
                nums.pop(result)
                count = 2
            else:
                pre = nums[result]
                result += 1
        return result

        # while result<n and nums[result] != last:
        #     if pre == nums[result]:
        #         count += 1
        #     else:
        #         count = 1
        #     pre = nums[result]
        #     if count == 3:
        #         nums.pop(result)
        #         count = 2
        #     else:
        #         result += 1
            
        # if nums[result-1] == last:
        #     return result
        # else:
        #     if result == n:
        #         return result
        #     else:
                
        # return result
s = Solution()
# print(s.removeDuplicates([1,1,1,2,2,3]))
print(s.removeDuplicates([0,0,1,1,1,1,2,3,3]))