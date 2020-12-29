class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        count = 0
        n = len(nums)
        i = k%n
        t = nums[0]
        while count < n:
            d = nums[i]
            nums[i] = t
            t = d
            i = (i+k)%n
            count += 1

s = Solution()
# print(s.rotate([1,2,3,4,5,6,7],3))
l = [1,2,3,4,5,6]
s.rotate(l,2)
print(l)