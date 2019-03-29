class Solution(object):
    def mysort(self,nums):
        if nums[0] > nums[1]:
            temp = nums[0]
            nums[0] = nums[1]
            nums[1] = temp
            
        if nums[1] > nums[2]:
            temp = nums[1]
            nums[1] = nums[2]
            nums[2] = temp
            
        if nums[0] > nums[1]:
            temp = nums[0]
            nums[0] = nums[1]
            nums[1] = temp
            
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        map_ = {}
        n = len(nums)
        for i in range(n):
            for j in range(i+1,n):
                t = nums[i]+nums[j]
                l = map_.get(t,[])
                l.append([i,j])
                map_[t] = l
                
        
        s = set()
        result = []
        for i in range(n):
            t = 0 - nums[i]
            if t in map_:
                l = map_[t]
                for ll in l:
                    if i not in ll:
                        lll = [nums[i]]
                        lll.extend([nums[ll[0]],nums[ll[1]]])
                        self.mysort(lll)
                        if str(lll) not in s:
                            result.append(lll)
                            s.add(str(lll))
                            
        return result

s = Solution()
print(s.threeSum( [0,0,0,0]))