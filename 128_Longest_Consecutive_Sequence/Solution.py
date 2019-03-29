class Solution(object):
    def getGroup(self,m,n):
        if m.get(n) != None:
            return m.get(n)
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        
        mx = 0
        s = set(nums)
        
        for n in nums:
            if n-1 not in s:
                cur = n
                c = 1
                while cur +1 in s:
                    c += 1
                    cur += 1
                mx = max(c,mx)
                
        return mx

s = Solution()
print(s.longestConsecutive([100,4,200,1,3,2]))        