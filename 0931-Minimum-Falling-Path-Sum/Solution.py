class Solution:
    # def xx(self,A,i,j,n,m,dp):
    #     if i==n or j == m:
    #         return 0
        
    #     if dp[i][j] != 0:
    #         return dp[i][j]
        
    #     if i == n -1:
    #         dp[i][j] = 1
    #     elif j == 0:
    #         dp[i][j] = self.xx(A,i+1,0,n,m,dp)+self.xx(A,i+1,1,n,m,dp)
    #     elif j == m -1:
    #         dp[i][j] = self.xx(A,i+1,j,n,m,dp)+self.xx(A,i+1,j-1,n,m,dp)
    #     else:
    #         dp[i][j] = self.xx(A,i+1,j,n,m,dp)+self.xx(A,i+1,j-1,n,m,dp)+self.xx(A,i+1,j+1,n,m,dp)
        
    #     return dp[i][j]
    def x(self,A,i,j,n,m,dp):
        if i==n or j == m:
            return 0
        
        if dp[i][j] != 0x7fffffff:
            return dp[i][j]
        
        if i == n -1:
            dp[i][j] = A[i][j]
        elif j == 0:
            dp[i][j] = A[i][j] + min(self.x(A,i+1,0,n,m,dp),self.x(A,i+1,1,n,m,dp))
        elif j == m -1:
            dp[i][j] = A[i][j] + min(self.x(A,i+1,j,n,m,dp),self.x(A,i+1,j-1,n,m,dp))
        else:
            dp[i][j] = A[i][j] + min(self.x(A,i+1,j,n,m,dp),self.x(A,i+1,j-1,n,m,dp),self.x(A,i+1,j+1,n,m,dp))
        
        return dp[i][j]

    def minFallingPathSum(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        n = len(A)
        m = len(A[0])
        dp = [([0x7fffffff]*m) for i in range(n)]
        for j in range(m):
            self.x(A,0,j,n,m,dp)
            
        return min(dp[0])

s = Solution()
# print(s.minFallingPathSum([[1,2,3],[4,5,6],[7,8,9]]))
# print(s.minFallingPathSum([[1,2],[3,4]]))
print(s.minFallingPathSum([[-80,-13,22],[83,94,-5],[73,-48,61]]))