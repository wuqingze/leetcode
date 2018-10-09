class Solution:
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 1:
            return True
        fmx = 0
        smx = 0
        if nums[0] == nums[1]:
            for i in range(2,n):
                if nums[i] != nums[0]:
                    fmx = max(nums[0],nums[i])
                    smx = min(nums[0],nums[i])
        else:
            fmx = max(nums[0],nums[1])
            smx = min(nums[0],nums[1])
            
        for i in range(2,n):
            if nums[i] > fmx:
                smx = fmx 
                fmx = nums[i]
            elif nums[i] < fmx:
                smx = max(nums[i],smx)
                
        return fmx >= smx*2

s = Solution()
print(s.dominantIndex([0,0,0,1]))