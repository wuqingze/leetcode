class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        fm = -0xffffffff
        sm = -0xffffffff
        tm = -0xffffffff
        flag = False
        for i in range(len(nums)):
            if nums[i] >= fm:
                if nums[i] > fm:
                    t = fm
                    fm = nums[i]
                    tm = sm
                    sm = t
            elif nums[i] >= sm:
                if nums[i] > sm:
                    t = sm
                    sm = nums[i]
                    tm = t
            elif nums[i] >= tm:
                flag = True
                tm = nums[i]
                
        if flag:
            return tm
        else:
            return fm

s = Solution()
# print(s.thirdMax([2,2,3,1]))
print(s.thirdMax([1,2,2,5,3,5]))