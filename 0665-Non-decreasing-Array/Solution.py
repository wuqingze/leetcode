class Solution:
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        modified = False
        s = -1
        f = -1
        n = len(nums)
        for i in range(n-1):
            if nums[i]>nums[i+1]:
                if modified:
                    s = i
                    break
                else:
                    f = i
                    modified = True
        if modified:
            if s == -1:
                if f == 0:
                    return True
                else:
                    if f == n-2:
                        return True
                    else:
                        return nums[f]<=nums[f+2]
            else:
                return False
        else:
            return True

s = Solution()
print(s.checkPossibility([2,3,3,2,4]))