class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        if nums == None or len(nums)<3:
            return None
        
        m = {}
        n = len(nums)
        for i in range(n):
            for j in range(i+1,n):
                t = nums[i]+nums[j]
                l = m.get(t,[])
                l.append((i,j))
                m[t] = l
        
        s = set()
        for i in range(n):
            t = 0-nums[i]
            tt = m.get(t,None)
            if tt:
                for v in tt:
                    if i == v[0] or i == v[1]:
                        continue
                    else:
                        s.add(str(sorted([nums[i],nums[v[0]],nums[v[1]]])))
                        
        return [[int(nn) for nn in arr[1:-1].split(',')] for arr in s]
        

s = Solution()
print(s.threeSum([-1,0,1,2,-1,-4]))