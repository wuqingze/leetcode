class Solution:

    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        templist = []
        start = 0
        n = len(nums)
        self.backtracking(nums,start,templist,result,n)
        return result
    
    def backtracking(self,nums,start,templist,result,n):
        result.append(list(templist))
        for i in range(start,n):
            templist.append(nums[i])
            self.backtracking(nums,i+1,templist,result,n)
            templist.pop(-1)

s = Solution()
print(s.subsets([1,2,3]))