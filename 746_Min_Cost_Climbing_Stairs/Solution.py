class Solution:
    def xx(self,cost,i,n,minl):
        if i >= n:
            return 0
        elif i == n-1:
            minl[i] = cost[i]
            return cost[i]
        elif i == n - 2:
            minl[i] = cost[i]
            return minl[i]
        elif minl[i] != 0x7fffffff:
            return minl[i]
        else:
            if minl[i+1] == 0x7fffffff:
                minl[i+1] = self.xx(cost,i+1,n,minl)
            if minl[i+2] == 0x7fffffff:
                minl[i+2] = self.xx(cost,i+2,n,minl)
            minl[i] =  cost[i]+ min(minl[i+1],minl[i+2])
            return minl[i]
        
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        n = len(cost)
        minl = [0x7fffffff]*(n+1)
        ans = self.xx([0]+cost,0,n+1,minl)
        
        return ans


s = Solution()
print(s.minCostClimbingStairs([0,1,0,0]))