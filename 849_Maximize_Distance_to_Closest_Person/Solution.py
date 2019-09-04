class Solution:
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        n = len(seats)
        left = [n]*n
        right = [n]*n
        
        for i in range(n):
            if seats[i] == 1:
                left[i] = 0
            elif i > 0:
                left[i] = left[i-1]+1
                
        for i in range(n-1):
            if seats[i] == 1:
                right[i] = 0
            elif i < n-1:
                right[i] = right[i+1]+1
                
        ans = 0
        for i in range(n):
            if seats[i] == 0:
                ans = max(ans,min(left[i],right[i]))
        return ans

s = Solution()
print(s.maxDistToClosest([1,0,0,0,1,0,1]))